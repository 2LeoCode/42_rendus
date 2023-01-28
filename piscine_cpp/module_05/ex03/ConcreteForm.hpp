/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConcreteForm.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:27:31 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/26 12:57:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

struct ConcreteForm : public Form {
	ConcreteForm();
	ConcreteForm(std::string, std::string, int, int, void (*)(std::string));
	ConcreteForm(const ConcreteForm&);
	virtual ~ConcreteForm();

	ConcreteForm	&operator =(const ConcreteForm&);

	Form			*create_instance(std::string) const;
};
