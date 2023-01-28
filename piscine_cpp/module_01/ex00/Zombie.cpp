/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:35:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 13:21:19 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() : _name("unnamed") { }

Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " died" << std::endl;
}

Zombie::Zombie(const std::string name) : _name(name) { }

void	Zombie::announce(void) {
	std::cout << '<' << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
