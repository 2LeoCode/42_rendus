/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:22:22 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/18 18:39:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define MAX_CONTACTS 8

class PhoneBook {
	public:

	PhoneBook();
	~PhoneBook();

	void	execute(const std::string &cmd);
	void	add(void);
	void	search(void);
	void	exit(void);

	private:

	std::string	formatField(unsigned field);
	std::string	formatField(std::string &field);
	std::string	formatField(const char *field);

	struct Contact {
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	}		_contact[MAX_CONTACTS];
	long	_contactCnt;
};
