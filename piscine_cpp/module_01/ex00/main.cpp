/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:41:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 17:08:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "UniquePtr.hpp"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void) {
	{
		// BAD

		Zombie	*joe, *bob, *marco;

		joe = bob = marco = NULL;
		try {
			joe = new Zombie("joe");
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			return -1;
		}
		try {
			bob = new Zombie("bob");
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			delete joe;
			return -1;
		}
		try {
			marco = new Zombie("marco");
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			delete joe;
			delete bob;
			return -1;
		}
		joe->announce();
		bob->announce();
		marco->announce();

		delete joe;
		delete bob;
		delete marco;
	}
	std::cout << std::endl;
	{
		// GOOD

		Zombie	joe("joe");
		Zombie	bob("bob");
		Zombie	marco("marco");

		joe.announce();
		bob.announce();
		marco.announce();
	}
	std::cout << std::endl;
	{
		// ALSO GOOD

		UniquePtr< Zombie >	joe, bob, marco;
		// I use a wrapper class to handle the pointer deletion for me

		try {
			joe = new Zombie("joe");
			bob = new Zombie("bob");
			marco = new Zombie("marco");
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (-1);
		}
		joe->announce();
		bob->announce();
		marco->announce();
	}
	std::cout << std::endl;
	randomChump("random");
	return (0);
}
