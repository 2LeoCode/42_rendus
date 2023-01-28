/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/22 18:56:34 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() { m_type = "Cat"; }

Cat::Cat(const Cat &other) : Animal(other) { }

Cat::~Cat() { }

Cat	&Cat::operator =(const Cat &other) {
	static_cast< void >(other);
	return *this;
}

void	Cat::makeSound(void) const { std::cout << "Meow" << std::endl; }

