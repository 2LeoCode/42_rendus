/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:57:51 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 11:36:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Bureaucrat.hpp"
# include "Form.hpp"

struct PresidentialPardonForm : public Form {
	PresidentialPardonForm(std::string target = "dummy");
};
