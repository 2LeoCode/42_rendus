/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:53:31 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 21:07:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() {
	m_name = ClapTrap::m_name;
	ClapTrap::m_name += "_clap_name";
	ClapTrap::m_ep = ScavTrap::m_ep;
	std::cout << "Created DiamondTrap " << m_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
:	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	m_name(other.m_name) {
	std::cout << "Created copy DiamondTrap " << m_name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destroyed DiamondTrap " << m_name << std::endl;
}

DiamondTrap	&DiamondTrap::operator =(const DiamondTrap &other) {
	m_name = other.m_name;
	dynamic_cast< ClapTrap& >(*this) = dynamic_cast< const ClapTrap& >(other);
	return *this;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name), ScavTrap(name), FragTrap(name) {
	m_name = ClapTrap::m_name;
	ClapTrap::m_name += "_clap_name";
	ClapTrap::m_ep = 50;
	std::cout << "Created DiamondTrap " << m_name << std::endl;
}

void	DiamondTrap::whoAmI(void) const {
	std::cout << m_name << ", " << ClapTrap::m_name << std::endl;
}
