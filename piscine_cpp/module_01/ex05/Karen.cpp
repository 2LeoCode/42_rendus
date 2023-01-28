/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:21:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 17:50:20 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <iostream>

std::string	Karen::m_debugMsg("I love to get extra bacon for my "
"XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!");

std::string	Karen::m_infoMsg("I cannot believe adding extra bacon cost more money."
"You don’t put enough! If you did I would not have to ask for it!");

std::string	Karen::m_warningMsg("I think I deserve to have some extra bacon for "
"free. I’ve been coming here for years and you just started working here last "
"month.");

std::string	Karen::m_errorMsg("This is unacceptable, I want to speak to the "
"manager now.");

Trie< Karen::ComplainFun >	Karen::m_data;

bool	Karen::m_init_trie(void) {
	m_data.insert("DEBUG", &Karen::debug);
	m_data.insert("INFO", &Karen::info);
	m_data.insert("WARNING", &Karen::warning);
	m_data.insert("ERROR", &Karen::error);
	return true;
}

Karen::Karen() { static bool init = m_init_trie(); (void)init; }

Karen::~Karen() { }

void	Karen::debug(void) { std::cout << m_debugMsg << std::endl; }

void	Karen::info(void) { std::cout << m_infoMsg << std::endl; }

void	Karen::warning(void) { std::cout << m_warningMsg << std::endl; }

void	Karen::error(void) { std::cout << m_errorMsg << std::endl; }

void	Karen::complain(std::string level) {
	(this->*m_data.search(level.c_str()))();
}
