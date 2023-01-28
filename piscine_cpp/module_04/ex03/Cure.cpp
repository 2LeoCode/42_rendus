/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:27:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/24 16:57:43 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cure.hpp"

Cure::Cure() : Materia("cure", "heals %'s wounds") { }

Cure::Cure(const Cure &other) : Materia(other) { }

Cure::~Cure() { }

Cure	&Cure::operator =(const Cure &other) {
	static_cast< void >(other);
	return *this;
}
