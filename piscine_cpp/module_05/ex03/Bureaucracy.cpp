/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucracy.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:00:22 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/26 11:16:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucracy.hpp"

Bureaucracy::Bureaucracy() { }

Bureaucracy::Bureaucracy(const Bureaucracy &other) {
	static_cast< void >(other);
}

Bureaucracy::~Bureaucracy(void) { }

Bureaucracy	&Bureaucracy::operator =(const Bureaucracy &other) {
	static_cast< void >(other);
	return *this;
}

const char	*Bureaucracy::GradeTooHighException::what(void) const throw () {
	return "Grade too high";
}

const char	*Bureaucracy::GradeTooLowException::what(void) const throw () {
	return "Grade too low";
}

const char *Bureaucracy::EAlreadySigned::what() const throw () {
	return "Form already signed";
}

const char *Bureaucracy::ENotSigned::what() const throw () {
	return "Form not signed";
}
