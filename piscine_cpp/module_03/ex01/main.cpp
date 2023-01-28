/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:46:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 18:25:19 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

int	main(int argc, char **argv) {
	std::string	option;

	if (argc == 2) option = argv[1];
	if (argc > 2 || (argc == 2 && option != "-d" && option != "--debug")) {
		std::cerr << "usage: " << argv[0] << " <-d|--debug>" << std::endl;
		return (-1);
	}
	ClapTrap	clap("clap");
	ScavTrap	scav("scav");

	if (argc == 2) {
		clap.enableDebugInfos();
		scav.enableDebugInfos();
	}
	try {
		scav.attack("dummy");
		clap.attack("dummy");
		scav.guardGate();
		scav.takeDamage(90);
		clap.takeDamage(90);
		scav.takeDamage(10);
		scav.takeDamage(10);
	} catch (std::string &err) {
		std::cout << err <<std::endl;
	}
	return (0);
}