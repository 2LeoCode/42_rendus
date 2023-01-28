/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:30:09 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 20:53:35 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
:	m_name("unnamed"),
	m_hp(10),
	m_ep(10),
	m_dmg(0),
	m_debugInfo(false) {
	std::cout << "Created ClapTrap " << m_name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destroyed ClapTrap " << m_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
:	m_name(other.m_name),
	m_hp(other.m_hp),
	m_ep(other.m_ep),
	m_dmg(other.m_dmg),
	m_debugInfo(false) {
	std::cout << "Created copy ClapTrap " << m_name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hp(10), m_ep(10), m_dmg(0),
	m_debugInfo(false) {
	std::cout << "Created ClapTrap " << m_name << std::endl;
}

ClapTrap	&ClapTrap::operator =(const ClapTrap &other) {
	m_name = other.m_name;
	m_hp = other.m_hp;
	m_ep = other.m_ep;
	m_dmg = other.m_dmg;
	return *this;
}

void	ClapTrap::attack(std::string const &target) {
	if (!m_hp) throw "ClapTrap " + m_name + " is not operational.";
	if (!m_ep) throw "ClapTrap " + m_name + " is out of energy.";
	--m_ep;
	std::cout << "ClapTrap " << m_name << " attacks " << target;
	std::cout << ", causing " << m_dmg << " points of damage!" << std::endl;
	std::cout << '<' << m_name << "> Yaaaaaah! 360 no-scope in your face!" << std::endl;
	if (m_debugInfo) debugInfo();
}

void	ClapTrap::takeDamage(unsigned amount) {
	if (m_hp <= 0) throw "ClapTrap " + m_name + " has already been destroyed.";
	std::cout << "ClapTrap " << m_name << " took " << amount;
	std::cout << " points of damage!" << std::endl;
	std::cout << '<' << m_name << "> Hey that hurts! ...wait, I'm a robot,"
	"I don't feel the pain, I'm invincible! MWAHAHAHAHAHA!" << std::endl;
	if (amount >= static_cast<unsigned>(m_hp)) {
		std::cout << "ClapTrap " << m_name << " has been destroyed!";
		std::cout << std::endl;
		std::cout << '<' << m_name << "> Segmentation fault. (core dumped)" << std::endl;
		m_hp = 0;
	} else m_hp -= amount;
	if (m_debugInfo) debugInfo();
}

void	ClapTrap::beRepaired(unsigned amount) {
	if (m_hp <= 0) throw "ClapTrap " + m_name + " can't be saved anymore.";
	m_hp += amount;
	std::cout << "ClapTrap " << m_name;
	std::cout << " has been repaired for " << amount << " HP!" << std::endl;
	std::cout << '<' << m_name << "> Mmmmh... that feels good!" << std::endl;
	if (m_debugInfo) debugInfo();
}

void	ClapTrap::enableDebugInfos(void) { m_debugInfo = true; }

void	ClapTrap::debugInfo(void) const {
	std::cerr << '\"' << "ClapTrap " << m_name << "\": {" << std::endl;
	std::cerr << "\t\"healthPoints\": " << m_hp << ',' << std::endl;
	std::cerr << "\t\"energyPoints\": " << m_ep << ',' << std::endl;
	std::cerr << "\t\"attackDamage\": " << m_dmg << std::endl;
	std::cerr << '}' << std::endl;
}
