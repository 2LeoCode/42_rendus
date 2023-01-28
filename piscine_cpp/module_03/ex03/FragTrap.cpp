/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:51:14 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 21:05:32 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	m_hp = 100;
	m_ep = 100;
	m_dmg = 30;
	std::cout << "Created FragTrap " << m_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "Created copy FragTrap " << m_name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Destroyed FragTrap " << m_name << std::endl;
}

FragTrap	&FragTrap::operator =(const FragTrap &other) {
	dynamic_cast< ClapTrap& >(*this) = dynamic_cast< const ClapTrap& >(other);
	return *this;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	m_hp = 100;
	m_ep = 100;
	m_dmg = 30;
	std::cout << "Created FragTrap " << m_name << std::endl;
}

void	FragTrap::highFiveGuys(void) const {
	std::cout << '<' << m_name <<
	"> I request a high five with positivity!" << std::endl;
}
