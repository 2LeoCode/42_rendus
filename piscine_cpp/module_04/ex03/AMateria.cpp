/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:13:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/24 17:39:34 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() : m_type("unknown") { }

AMateria::~AMateria() { }

AMateria::AMateria(const AMateria &other) : m_type(other.m_type) { }

AMateria::AMateria(const std::string &type) : m_type(type) { }

AMateria	&AMateria::operator =(const AMateria &other) {
	m_type = other.m_type;
	return *this;
}

const std::string	&AMateria::getType(void) const { return m_type; }
