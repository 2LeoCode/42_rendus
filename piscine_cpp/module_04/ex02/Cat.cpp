/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 13:35:33 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : m_brain(new Brain) { m_type = "Cat"; }

Cat::Cat(const Cat &other)
:	Animal(other),
	m_brain(new Brain(*other.m_brain)) { }

Cat::~Cat() { delete m_brain; }

Cat	&Cat::operator =(const Cat &other) {
	delete m_brain;
	m_brain = new Brain(*other.m_brain);
	return *this;
}

void	Cat::makeSound(void) const { std::cout << "Meow" << std::endl; }
