/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:28:15 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 13:00:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "UniquePtr.hpp"

#include <iostream>
#include <typeinfo>

static const std::string formType[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

static ConcreteForm	concreteForms[3] = {
	ShrubberyCreationForm(),
	RobotomyRequestForm(),
	PresidentialPardonForm()
};

Intern::Intern() { }

Intern::Intern(const Intern &other) { static_cast< void >(other); }

Intern::~Intern() { }

Intern	&Intern::operator =(const Intern &other) {
	static_cast< void >(other);
	return *this;
}

Form *Intern::makeForm(std::string type, std::string target) {
	for (unsigned i = 0; i < 3; ++i)
		if (type == formType[i]) {
			std::cout << "Intern creates a " << type << " form" << std::endl;
			return concreteForms[i].create_instance(target);
		}
	throw EDoesNotExist();
	return (NULL);
}

const char	*Intern::EDoesNotExist::what(void) const throw () {
	return "Form does not exist";
}
