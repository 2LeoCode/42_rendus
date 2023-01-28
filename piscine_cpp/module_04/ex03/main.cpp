/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:23:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 16:34:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "UniquePtr.hpp"
#include "Trie.hpp"

#include <iostream>
#include <stdexcept>

int	main(void) {
	UniquePtr< ICharacter >	bob, jack;
	UniquePtr< AMateria >	materias[7];
	UniquePtr< AMateria >	cure;
	MateriaSource			src;

	try {
		bob = new Character("Bob");
		jack = new Character("Jack");

		cure = src.createMateria("cure");
		materias[0] = src.createMateria("cure");
		materias[1] = src.createMateria("ice");
		materias[2] = src.createMateria("fireball");
		materias[3] = src.createMateria("poison");
		materias[4] = src.createMateria("earthquake");
		materias[5] = src.createMateria("armor");
		materias[6] = src.createMateria("necromancy");

		bob->equip(&*materias[0]);
		bob->equip(&*materias[1]);
		bob->equip(&*materias[2]);
		bob->equip(&*materias[3]);
		try {
			bob->equip(&*materias[4]);
		} catch (const Character::EInventoryFull &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		jack->equip(&*materias[4]);
		jack->equip(&*materias[5]);
		jack->equip(&*materias[6]);
		bob->unequip(0);
		bob->equip(&*cure);
	
		src.learnMateria(&*materias[0]);
		src.learnMateria(&*materias[1]);
		src.learnMateria(&*materias[2]);
		src.learnMateria(&*materias[3]);
		try {
			src.learnMateria(&*materias[4]);
		} catch (const std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		src.unlearnMateria(2);
		src.learnMateria(&*materias[4]);
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return -1;
	}
	bob->use(0, *jack);
	bob->use(1, *jack);
	bob->use(2, *jack);
	bob->use(3, *jack);
	jack->use(0, *bob);
	jack->use(1, *bob);
	jack->use(2, *bob);
	try {
		jack->use(3, *bob);
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
