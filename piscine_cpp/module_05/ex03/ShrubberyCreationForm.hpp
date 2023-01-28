/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:37:04 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 12:59:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "ConcreteForm.hpp"

struct ShrubberyCreationForm : public ConcreteForm {
	ShrubberyCreationForm(std::string target = "dummy");
	Form	*create_instance(std::string) const;
};
