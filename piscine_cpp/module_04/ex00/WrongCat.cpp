/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/22 18:50:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() { m_type = "WrongCat"; }

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) { }

WrongCat	&WrongCat::operator =(const WrongCat &other) {
	static_cast< void >(other);
	return *this;
}

WrongCat::~WrongCat() { }
