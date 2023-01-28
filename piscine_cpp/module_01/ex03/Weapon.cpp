/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:17:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 15:13:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) { }

Weapon::~Weapon() { }

const std::string	&Weapon::getType(void) const {
	return (_type);
}

void	Weapon::setType(std::string newType) {
	_type = newType;
}
