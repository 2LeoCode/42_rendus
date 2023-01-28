/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:46:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/02/13 20:15:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Random.hpp"

#include <stdlib.h>
#include <ctime>
#include <stdexcept>

char	Random::m_statebuf[STATEBUF_SIZE] = { };

Random::Random() {
	static bool	init = m_init();
	static_cast< void >(init);
}

Random::~Random() { }

bool	Random::m_init(void) {
	std::time_t	seed = std::time(NULL);
	initstate(seed, m_statebuf, STATEBUF_SIZE);
	setstate(m_statebuf);
	return true;
}

int		Random::operator ()(const int &min, const int &max) {
	if (min > max)
		throw std::invalid_argument("Random::operator ()");
	return random() % (max - min + 1) + min;
}
