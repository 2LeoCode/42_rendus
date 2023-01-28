/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:16:54 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 12:59:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "ConcreteForm.hpp"

struct RobotomyRequestForm : public ConcreteForm {
	RobotomyRequestForm(std::string target = "dummy");
	Form	*create_instance(std::string) const;
};
