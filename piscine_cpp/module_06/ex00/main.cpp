/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:40:44 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 15:53:42 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Litteral.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " <litteral>" << std::endl;
		return -1;
	}


	Litteral	litteral;

	try {
		litteral = argv[1];
	} catch (std::exception &e) {
		std::cerr << "exception caught: " << e.what() << std::endl;
		return -1;
	}
	litteral.print();
	return 0;
}
