/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:52:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 16:43:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <stdexcept>

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Trie.hpp"
#include "utils.hpp"

static Trie< AMateria >	g_materiaTrie;

static bool	initMaterias(void) {
	std::ifstream	dataFile("Materias.txt", std::ios::in);
	Materia			tmp;

	if (dataFile.bad())
		throw std::runtime_error("can't open Materias.txt");
	g_materiaTrie.insert("cure", new Cure);
	g_materiaTrie.insert("ice", new Ice);
	while (dataFile >> tmp)
		g_materiaTrie.insert(tmp.getType().c_str(), new Materia(tmp));
	return true;
}

MateriaSource::MateriaSource() {
	static bool	init = initMaterias();

	static_cast< void >(init);
	ft::fill(m_occupied, m_occupied + 4, false);
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (std::size_t i = 0; i < 4; ++i)
		if (other.m_occupied[i]) {
			m_inventory[i] = other.m_inventory[i]->clone();
			m_occupied[i] = true;
		}
}

MateriaSource::~MateriaSource() {
	for (
		List< AMateria* >::node *ptr = m_addr.head();
		ptr;
		ptr = ptr->next
	) delete ptr->data;
}

MateriaSource	&MateriaSource::operator =(const MateriaSource &other) {
	for (std::size_t i = 0; i < 4; ++i)
		if (other.m_occupied[i]) {
			m_addr.push_back(m_inventory[i] = other.m_inventory[i]->clone());
			m_occupied[i] = true;
		}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *mat) {
	for (int i = 0; i < 4; ++i)
		if (!m_occupied[i]) {
			m_addr.push_back(m_inventory[i] = mat->clone());
			m_occupied[i] = true;
			return ;
		}
	throw EInventoryFull();
}

void	MateriaSource::unlearnMateria(int slot) {
	if (slot >= 4)
		throw std::out_of_range("MateriaSource::unlearnMateria");
	m_occupied[slot] = false;
}

AMateria	*MateriaSource::createMateria(const std::string &type) {
	return g_materiaTrie.search(type.c_str())->clone();
}

const char	*MateriaSource::EInventoryFull::what(void) const throw () {
	return "MateriaSource inventory is full";
}
