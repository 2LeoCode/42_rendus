/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:43:27 by lsuardi           #+#    #+#             */
/*   Updated: 2022/01/24 17:40:55 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

Materia::Materia() : AMateria(), m_msg("???") { }

Materia::Materia(const Materia &other)
:	AMateria(other),
	m_msg(other.m_msg)
{ }

Materia::Materia(std::string type, std::string msg)
:	AMateria(type),
	m_msg(msg) { }

Materia::~Materia() { }

Materia	&Materia::operator =(const Materia &other) {
	m_type = other.m_type;
	m_msg = other.m_msg;
	return *this;
}

AMateria	*Materia::clone(void) const { return new Materia(*this); }

void	Materia::use(ICharacter &target) {
	std::string	output("* " + m_msg + " *");

	output.replace(output.find_first_of('%'), 1, target.getName());
	std::cout << output << std::endl;
}

std::istream	&operator >>(std::istream &in, Materia &m) {
	std::string	type, msg, dummy;
	char		c;

	if (
		std::getline(in, type, ' ')
		&& in >> c
		&& c == '"' && std::getline(in, msg, '"')
		&& std::getline(in, dummy)
	) m = Materia(type, msg);
	else
		in.setstate(std::ios::failbit);
	return in;
}
