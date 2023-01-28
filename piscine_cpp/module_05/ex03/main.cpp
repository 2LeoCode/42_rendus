/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:53:50 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 12:51:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "UniquePtr.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int	main(void) {
	Intern kevin;
	UniquePtr< Form > rob, shrub, presidential;
	Bureaucrat	bob("Bob", 1);

	rob = kevin.makeForm("robotomy request", "A-01");
	shrub = kevin.makeForm("shrubbery creation", "B-00");
	presidential = kevin.makeForm("presidential pardon", "B-01");
	try {
		kevin.makeForm("foo", "bar");
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
