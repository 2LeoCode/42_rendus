/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:45:50 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 11:38:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>

#include <cstdlib>

void requestRobotomy(std::string target) {
	std::cout << "* drill noises *" << std::endl;

	if (random() % 2)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << "Failed to robotomize " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:	Form("robotomy request", target, 72, 45, requestRobotomy)
{ }
