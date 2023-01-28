/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:46:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 13:41:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*horde;

	try {
		horde = new Zombie[N];
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}
	return horde;
}
