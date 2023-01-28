/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:00:02 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 11:38:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

void doPresidentialPardon(std::string target) {
	std::cout << target << " has been pardonned by Zafod Beeblebrox" <<
	std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:	Form("pardon", target, 25, 5, doPresidentialPardon)
{ }
