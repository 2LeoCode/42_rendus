/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:42:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 21:10:11 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

int	main(void) {
	FragTrap	fraggy("Fraggy");
	ScavTrap	scavy("Scavy");

	//scavy.enableDebugInfos();
	fraggy.highFiveGuys();
	DiamondTrap	jamy("Jamy");

	//jamy.enableDebugInfos();
	std::cout << "<Jamy> MWAHAHAHAHA! I'M MEAN!" << std::endl;
	jamy.attack("Everyone");
	scavy.takeDamage(3567587328);
	fraggy.takeDamage(3567587328);
	jamy.guardGate();
	jamy.highFiveGuys();
	jamy.whoAmI();
	return (0);
}
