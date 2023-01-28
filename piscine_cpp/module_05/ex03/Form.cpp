/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:21:31 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 11:29:04 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

Form::Form()
:	m_name("generic"),
	m_target("dummy"),
	m_gradeToSign(150),
	m_gradeToExec(150),
	m_action(NULL)
{ }

Form::Form(
	std::string name, std::string target,
	int gradeToSign, int gradeToExec,
	void (*action)(std::string)
) :	m_name(name),
	m_target(target),
	m_gradeToSign(gradeToSign),
	m_gradeToExec(gradeToExec),
	m_action(action) {
	if (m_gradeToSign < 1 || m_gradeToExec < 1)
		throw GradeTooHighException();
	if (m_gradeToSign > 150 || m_gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
:	m_name(other.m_name),
	m_target(other.m_target),
	m_gradeToSign(other.m_gradeToSign),
	m_gradeToExec(other.m_gradeToExec),
	m_action(other.m_action)
{ }

Form::~Form() { }

Form	&Form::operator =(const Form &other) {
	static_cast< void >(other);
	return *this;
}

const std::string &Form::getName(void) const { return m_name; }

int Form::gradeToSign(void) const { return m_gradeToSign; }

int Form::gradeToExec(void) const { return m_gradeToExec; }

bool Form::isSigned(void) const { return m_signed; }

Form &Form::beSigned(const Bureaucrat &b) {
	if (m_signed)
		throw EAlreadySigned();
	if (b.getGrade() > m_gradeToSign)
		throw GradeTooLowException();
	std::cout << b.getName() << " signs " << m_name << std::endl;
	m_signed = true;
	return *this;
}

const Form &Form::execute(const Bureaucrat &b) const {
	if (!m_signed)
		throw ENotSigned();
	if (b.getGrade() > m_gradeToExec)
		throw GradeTooLowException();
	std::cout << b.getName() << " executes " << m_name << std::endl;
	if (m_action)
		m_action(m_target);
	else
		std::cout << "But nothing happens..." << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &out, Form &f) {
	return out << f.getName() << " form grade to sign " << f.gradeToSign() <<
		", grade to execute " << f.gradeToExec() << '.' << std::endl <<
		"Signed: " << (f.isSigned() ? "true" : "false") << std::endl;
}
