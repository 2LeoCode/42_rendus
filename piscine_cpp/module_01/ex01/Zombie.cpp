/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:35:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 13:45:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() : _name("unnamed") { }

Zombie::Zombie(std::string &name) : _name(name) { }

Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " died" << std::endl;
}

Zombie	Zombie::operator =(const Zombie &src) {
	_name = src._name;
	return (*this);
}

void	Zombie::announce(void) {
	std::cout << '<' << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { _name = name; }
