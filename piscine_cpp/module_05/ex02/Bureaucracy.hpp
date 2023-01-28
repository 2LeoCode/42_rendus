/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucracy.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:53:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/26 11:17:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

struct Bureaucracy {
	Bureaucracy();
	Bureaucracy(const Bureaucracy &other);
	virtual ~Bureaucracy() = 0;

	virtual Bureaucracy	&operator =(const Bureaucracy &other);

	struct GradeTooHighException : public std::exception {
		const char	*what() const throw();
	};
	struct GradeTooLowException : public std::exception {
		const char	*what() const throw();
	};
	struct EAlreadySigned : public std::exception {
		const char	*what() const throw ();
	};
	struct ENotSigned : public std::exception {
		const char	*what() const throw ();
	};
};
