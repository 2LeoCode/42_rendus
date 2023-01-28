/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:00:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/22 18:56:39 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() { m_type = "Dog"; }

Dog::Dog(const Dog &other) : Animal(other) { }

Dog::~Dog( ) { }

Dog	&Dog::operator =(const Dog &other) {
	static_cast< void >(other);
	return *this;
}

void	Dog::makeSound(void) const { }
