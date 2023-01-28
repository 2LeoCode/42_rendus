/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:58:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 17:08:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "UniqueArrayPtr.hpp"

#include <iostream>

#include <cstdlib>
#include <ctime>

Zombie	*zombieHorde(int N, std::string name);

static int	randomBetween(int min, int max) {
	return (min + random() % (max - min + 1));
}

static void	unleashHorde(size_t hordeSize, UniqueArrayPtr< Zombie > &horde) {
	for (size_t i = 0; i < hordeSize; ++i)
		horde[i].announce();
}

int	main(int argc, char **argv) {
	if (argc == 1) return (0);
	UniqueArrayPtr< Zombie >	hordes[argc - 1];
	size_t						hordeSizes[argc - 1];

	srandom(std::time(NULL));
	for (int i = 1; i < argc; ++i) {
		hordeSizes[i - 1] = static_cast<size_t>(randomBetween(5, 20));
		std::cout << "Creating a horde with " << hordeSizes[i - 1];
		std::cout << " zombies named " << argv[i] <<  std::endl;
		try {
			hordes[i - 1] = zombieHorde(hordeSizes[i - 1], argv[i]);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (-1);
		}
	}
	std::cout << "\n\nUnleashing hordes\n" << std::endl;
	for (int i = 0; i < argc - 1; ++i) {
		unleashHorde(hordeSizes[i], hordes[i]);
		std::cout << std::endl;
	}
	std::cout << "\nDestroying hordes\n" << std::endl;
	return (0);
}
