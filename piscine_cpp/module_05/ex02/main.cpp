/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:03:03 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 11:20:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	ShrubberyCreationForm	shrub("jeff the tree");
	RobotomyRequestForm		rob("jeff the buddy");
	PresidentialPardonForm	pardon("jeff the killer");

	Bureaucrat				a("A", 150), b("B", 100), c("C", 50), d("D", 1);
	a.executeForm(shrub);
	a.signForm(shrub), b.signForm(shrub), c.signForm(shrub), d.signForm(shrub);
	a.signForm(rob), b.signForm(rob), c.signForm(rob), d.signForm(rob);
	a.signForm(pardon), b.signForm(pardon), c.signForm(pardon), d.signForm(pardon);
	a.executeForm(shrub), b.executeForm(shrub), c.executeForm(shrub), d.executeForm(shrub);
	a.executeForm(rob), b.executeForm(rob), c.executeForm(rob), d.executeForm(rob);
	a.executeForm(pardon), b.executeForm(pardon), c.executeForm(pardon), d.executeForm(pardon);
	return 0;
}
