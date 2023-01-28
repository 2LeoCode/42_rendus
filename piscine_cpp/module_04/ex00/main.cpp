/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:11:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 14:03:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UniquePtr.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int	main(void) {
	UniquePtr< const Animal >	meta, i, j;
	UniquePtr< const WrongAnimal >	k;

	try {
		meta = new Animal();
		j = new Dog();
		i = new Cat();
		k = new WrongCat();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << k->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	return 0;
}
