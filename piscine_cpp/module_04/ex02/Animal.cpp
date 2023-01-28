/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 14:04:46 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : m_type("???") { };

Animal::Animal(const Animal &other) : m_type(other.m_type) { }

Animal::~Animal() { }

Animal	&Animal::operator =(const Animal &other) {
	m_type = other.m_type;
	return *this;
}

const std::string	&Animal::getType(void) const { return m_type; }
