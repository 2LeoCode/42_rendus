/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:00:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 13:42:09 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : m_brain(new Brain) { m_type = "Dog"; }

Dog::Dog(const Dog &other)
:	Animal(other),
	m_brain(new Brain(*other.m_brain)) { }

Dog::~Dog( ) { delete m_brain; }

Dog	&Dog::operator =(const Dog &other) {
	delete m_brain;
	m_brain = new Brain(*other.m_brain);
	return *this;
}

void	Dog::makeSound(void) const { std::cout << "Bark" << std::endl; }
