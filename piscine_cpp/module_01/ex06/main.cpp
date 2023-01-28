/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:50:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 17:52:19 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <iostream>

const char	*karenLevels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

void	complainAtLevel(Karen &karen, int level, int filterLevel) {
	if (level >= filterLevel) {
		std::cout << "[ " << karenLevels[level] << " ]" << std::endl;
		karen.complain(karenLevels[level]);
		std::cout << std::endl;
	}
}

int	main(int argc, char **argv) {
	int					filterLevel = 0;
	std::string			levelString;
	Karen				karen;

	if (argc == 1) filterLevel = 4;
	else {
		levelString = argv[1];
		for (int i = 0; i < 4; ++i)
			if (levelString != karenLevels[i]) ++filterLevel;
			else break ;
	}
	if (filterLevel == 4) {
		std::cout << "[ Probably complaining about insignificant problems ]";
		std::cout << std::endl;
	} else for (int i = 0; i < 4; ++i)
		complainAtLevel(karen, i, filterLevel);
	return (0);
}
