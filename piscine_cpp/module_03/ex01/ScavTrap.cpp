#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	m_hp = 100;
	m_ep = 50;
	m_dmg = 10;
	std::cout << "Created ScavTrap " << m_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "Created copy ScavTrap " << m_name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destroyed ScavTrap " << m_name << std::endl;
}

ScavTrap	&ScavTrap::operator =(const ScavTrap &other) {
	dynamic_cast< ClapTrap& >(*this) = dynamic_cast< const ClapTrap& >(other);
	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	m_hp = 100;
	m_ep = 50;
	m_dmg = 10;
	std::cout << "Created ScavTrap " << m_name << std::endl;
}

void	ScavTrap::attack(std::string target) {
	std::cout << '<' << m_name <<
	"> Scaving the ennemies....." << std:: endl << target <<
	" got scaved for " << m_dmg << " damage points." << std::endl;
}

void	ScavTrap::guardGate(void) {
	if (m_ep < 2) throw "ScavTrap " + m_name + " is out of energy.";
	m_ep -= 2;
	std::cout << "ScavTrap " << m_name <<
	" has entered in Gate Keeper mode. BE AWARE" << std::endl;
	if (m_debugInfo) debugInfo();
}
