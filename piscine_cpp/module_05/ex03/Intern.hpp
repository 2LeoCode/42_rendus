/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:22:03 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 12:40:20 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

#include <string>

struct Intern {
	Intern();
	Intern(const Intern&);
	~Intern();

	Intern	&operator =(const Intern&);
	Form *makeForm(std::string type, std::string target);
	struct EDoesNotExist : public std::exception {
		const char	*what(void) const throw ();
	};
};
