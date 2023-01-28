/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConcreteForm.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:29:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/26 12:58:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConcreteForm.hpp"

ConcreteForm::ConcreteForm() : Form() { }

ConcreteForm::ConcreteForm(const ConcreteForm &other) : Form(other) { }

ConcreteForm::ConcreteForm(
	std::string name, std::string target,
	int gradeToSign, int gradeToExec,
	void (*action)(std::string)
) :	Form(name, target, gradeToSign, gradeToExec, action) { }

ConcreteForm::~ConcreteForm() { }

Form	*ConcreteForm::create_instance(std::string target) const {
	return new ConcreteForm(
		m_name, target, m_gradeToSign, m_gradeToExec, m_action
	);
}

ConcreteForm	&ConcreteForm::operator =(const ConcreteForm &other) {
	static_cast< void >(other);
	return *this;
}
