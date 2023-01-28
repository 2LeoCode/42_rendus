/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:57:51 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 12:58:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Bureaucrat.hpp"
# include "ConcreteForm.hpp"

struct PresidentialPardonForm : public ConcreteForm {
	PresidentialPardonForm(std::string target = "dummy");
	Form	*create_instance(std::string) const;
};
