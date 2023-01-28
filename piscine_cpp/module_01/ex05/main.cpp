/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:50:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 17:48:54 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Karen.hpp"

int	main(void) {
	Karen	karen;

	karen.complain("WARNING");
	karen.complain("DEBUG");
	karen.complain("ERROR");
	karen.complain("INFO");
	try {
		karen.complain("LOL");
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
