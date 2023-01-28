/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:49:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 15:13:07 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>
#include <cstddef>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) { }

HumanB::~HumanB() { }

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void	HumanB::attack(void) const {
	if (!_weapon) throw std::runtime_error(_name + " has no weapon");
	std::cout << _name << " attacks with his " << _weapon->getType();
	std::cout << std::endl;
}
