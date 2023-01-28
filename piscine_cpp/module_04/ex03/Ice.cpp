/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:22:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/24 16:56:55 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Ice.hpp"

Ice::Ice() : Materia("ice", "shoots an ice bolt at %") { }

Ice::Ice(const Ice &other) : Materia(other) { }

Ice::~Ice() { }

Ice	&Ice::operator =(const Ice &other) {
	static_cast< void >(other);
	return *this;
}
