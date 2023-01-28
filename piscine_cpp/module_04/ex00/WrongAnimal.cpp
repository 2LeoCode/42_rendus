/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/22 18:21:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : m_type("???") { }

WrongAnimal::WrongAnimal(const WrongAnimal &other) : m_type(other.m_type) { }

WrongAnimal::~WrongAnimal() { }

WrongAnimal	&WrongAnimal::operator =(const WrongAnimal &other) {
	m_type = other.m_type;
	return *this;
}

void	WrongAnimal::makeSound(void) const { std::cout << "???" << std::endl; }

const std::string	&WrongAnimal::getType(void) const { return m_type; }
