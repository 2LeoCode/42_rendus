/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:31:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 13:38:18 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain() { }

Brain::~Brain() { }

Brain::Brain(const Brain &other) {
	for (unsigned i = 0; i < 100; ++i)
		m_ideas[i] = other.m_ideas[i];
}

Brain	&Brain::operator =(const Brain &other) {
	for (unsigned i = 0; i < 100; ++i)
		m_ideas[i] = other.m_ideas[i];
	return *this;
}
