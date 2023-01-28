/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:21:31 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 11:06:21 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

Form::Form()
:	m_name("Unnamed form"),
	m_gradeToSign(150),
	m_signed(false)
{ }

Form::~Form() { }

Form::Form(const Form &other)
:	m_name(other.m_name),
	m_gradeToSign(other.m_gradeToSign)
{ }

Form::Form(std::string name)
:	m_name(name),
	m_gradeToSign(150),
	m_signed(false)
{ }

Form::Form(std::string name, int gradeToSign)
:	m_name(name),
	m_gradeToSign(gradeToSign),
	m_signed(false) {
	if (m_gradeToSign < 1)
		throw GradeTooHighException();
	else if (m_gradeToSign > 150)
		throw GradeTooLowException();
}

Form	&Form::operator =(const Form &other) {
	static_cast< void >(other);
	return *this;
}

const std::string &Form::getName(void) const { return m_name; }

int Form::gradeToSign(void) const { return m_gradeToSign; }

bool Form::isSigned(void) const { return m_signed; }

Form &Form::beSigned(const Bureaucrat &b) {
	if (m_signed)
		throw EAlreadySigned();
	if (b.getGrade() > m_gradeToSign)
		throw GradeTooLowException();
	std::cout << b.getName() << " signed " << m_name << std::endl;
	m_signed = true;
	return *this;
}

std::ostream &operator<<(std::ostream &out, Form &f) {
	return out << f.getName() << " form: grade to sign " <<
		f.gradeToSign() << '.' << " Signed: " <<
		(f.isSigned() ? "true" : "false");
}
