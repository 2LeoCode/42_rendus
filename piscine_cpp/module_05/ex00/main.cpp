/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:25:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/26 10:29:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int	main(void) {
	Bureaucrat	a, b("jack"), c("joe", 1);

	std::cout << a << '\n' << b << '\n' << c << '\n' << std::endl;
	std::cout << "Creating bureaucrat dummy with grade 151" << std::endl;
	try {
		Bureaucrat	d("dummy", 151); // GradeTooLowException
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}
	std::cout << "Creating bureaucrat dummy with grade 0" << std::endl;
	try {
		Bureaucrat	e("dummy", 0); // GradeTooHighException
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}
	std::cout << "Upgrading " << a.getName() << std::endl;
	a.upgrade();
	std::cout << "Upgrading " << c.getName() << std::endl;
	try {
		c.upgrade(); // GradeTooHighException
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}
	std::cout << "Downgrading " << c.getName() << std::endl;
	c.downgrade();
	std::cout << "Downgrading " << b.getName() << std::endl;
	try {
		b.downgrade(); // GradeTooLowException
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}
	std::cout << a << std::endl << b << std::endl << c << std::endl;
	return 0;
}