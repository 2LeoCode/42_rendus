/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:38:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 14:41:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <stdexcept>

#include "Character.hpp"
#include "utils.hpp"

Character::Character() : m_name("unnamed"), m_addr() {
	ft::fill(m_occupied, m_occupied + 4, false);
}

Character::~Character() {
	for (
		List< AMateria* >::node *ptr = m_addr.head();
		ptr;
		ptr = ptr->next
	) delete ptr->data;
}

Character::Character(const Character &other)
:	m_name(other.m_name), m_addr() {
	for (int i = 0; i < 4; ++i)
		if (other.m_occupied[i]) {
			m_addr.push_back(m_inventory[i] = other.m_inventory[i]->clone());
			m_occupied[i] = true;
		} else
			m_occupied[i] = false;
}

Character::Character(std::string name) : m_name(name), m_addr() {
	ft::fill(m_occupied, m_occupied + 4, false);
}

Character	&Character::operator =(const Character &other) {
	m_name = other.m_name;
	for (int i = 0; i < 4; ++i)
		if (other.m_occupied[i]) {
			m_addr.push_back(m_inventory[i] = other.m_inventory[i]->clone());
			m_occupied[i] = true;
		} else
			m_occupied[i] = false;
	return *this;
}

const std::string	&Character::getName() const { return m_name; }

void				Character::equip(AMateria *m) {
	for (int i = 0; i < 4; ++i) {
		if (!m_occupied[i]) {
			m_addr.push_back(m_inventory[i] = m->clone());
			m_occupied[i] = true;
			return ;
		}
	}
	throw EInventoryFull();
}

void				Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		throw std::out_of_range("Character::unequip");
	m_occupied[idx] = false;
}

void				Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 4 || !m_occupied[idx])
		throw std::out_of_range("Character::use");
	m_inventory[idx]->use(target);
}

const char	*Character::EInventoryFull::what(void) const throw () {
	return "Character inventory is full";
}
