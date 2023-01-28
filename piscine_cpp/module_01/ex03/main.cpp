/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:57:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 17:08:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#include <iostream>

int main(void) {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

		try {
			jim.attack();
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		jim.setWeapon(club);
		try {
			jim.attack();
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
