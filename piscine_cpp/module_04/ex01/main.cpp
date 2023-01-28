/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:38:01 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 16:48:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "UniquePtr.hpp"

#include <iostream>
#include <sstream>

#ifdef COPYTEST

int	main(void) {
	UniquePtr< Cat > dstCat, srcCat;
	UniquePtr< Dog > dstDog, srcDog;

	try {
		srcCat = new Cat(), srcDog = new Dog();
		dstCat = new Cat(*srcCat), dstDog = new Dog(*srcDog);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	dstCat->makeSound();
	dstDog->makeSound();
	return (0);
}

#else

int	main(int argc, char **argv) {
	unsigned	size;

	if (argc != 2 || std::string(argv[1]).find_first_not_of("0123456789")
	!= std::string::npos) {
		std::cout << "Usage: " << argv[0] << " <arraySize>" << std::endl;
		return 1;
	}
	std::istringstream(argv[1]) >> size;
	UniquePtr< Animal >	animals[size];
	try {
		for (unsigned i = 0; i < size / 2; ++i)
			animals[i] = new Cat();
		for (unsigned i = size / 2; i < size; ++i)
			animals[i] = new Dog();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	for (unsigned i = 0; i < size; ++i)
		animals[i]->makeSound();
	return 0;
}

#endif