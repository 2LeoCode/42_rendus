/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:52:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/18 19:00:35 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

#include <iomanip>
#include <sstream>

#include <cstdlib>
#include <cstring>
#include <cerrno>

typedef std::string::iterator	string_iterator;

PhoneBook::PhoneBook() : _contactCnt(0) { }

PhoneBook::~PhoneBook() {
	std::cout << "Destructor has been called" << std::endl;
}

static std::string	getInput(const char *msg) {
	std::string	inputLine;

	std::cout << msg << ": ";
	std::getline(std::cin, inputLine);
	return (inputLine);
}

static std::string	getName(const char *msg) {
	std::string	inputLine;
	bool		validInput = false;

	while (!validInput) {
		std::cout << msg << " [a-z/A-Z]: ";
		std::getline(std::cin, inputLine);
		string_iterator	it(inputLine.begin());

		ft::advance_while(it, inputLine.end(), ft::is_space);
		ft::advance_while(it, inputLine.end(), ft::is_name);
		ft::advance_while(it, inputLine.end(), ft::is_space);
		if (it == inputLine.end()) validInput = true;
		else std::cerr << "INVALID INPUT" << std::endl;
	}
	return (inputLine);
}

static std::string	getPhoneNumber(const char *msg) {
	std::string		finalStr;
	while (42) {
		std::string		inputLine;
	
		std::cout << msg << " [0-9]: ";
		std::getline(std::cin, inputLine);

		string_iterator it(inputLine.begin());
		unsigned		cnt(0);

		finalStr = "";
		while (it != inputLine.end()) {
			if (!std::isspace(*it) && !std::isdigit(*it)) break ;
			ft::advance_while(it, inputLine.end(), ft::is_space);
			while (it != inputLine.end() && std::isdigit(*it)) {
				if (cnt && !(cnt % 2)) finalStr += ' ';
				if (++cnt > 10) goto end_loop;
				finalStr += *it++;
			}
		}
		end_loop:
		if (cnt == 10 && it == inputLine.end()) break ;
		else std::cout << "INVALID INPUT" << std::endl;
	}
	return (finalStr);
}

void	PhoneBook::add(void) {
	if (_contactCnt == MAX_CONTACTS) {
		std::cerr << "PHONEBOOK IS FULL" << std::endl;
		return ;
	}
	_contact[_contactCnt].firstName = getName("FIRST NAME");
	_contact[_contactCnt].lastName = getName("LAST NAME");
	_contact[_contactCnt].nickname = getInput("NICKNAME");
	_contact[_contactCnt].phoneNumber = getPhoneNumber("PHONE NUMBER");
	_contact[_contactCnt++].darkestSecret = getInput("DARKEST SECRET");
}

std::string	PhoneBook::formatField(unsigned field) {
	std::ostringstream	stream;

	stream << std::setw(10) << field << std::setw(0);
	return (stream.str());
}

std::string	PhoneBook::formatField(std::string &field) {
	std::ostringstream	stream;

	if (field.length() > 10)
		stream << std::string(field.begin(), field.begin() + 9) << '.';
	else stream << std::setw(10) << field << std::setw(0);
	return (stream.str());
}

std::string	PhoneBook::formatField(const char *field) {
	std::ostringstream	stream;

	if (std::strlen(field) > 10)
		stream << std::string(field, field + 9) << '.';
	else stream << std::setw(10) << field << std::setw(0);
	return (stream.str());
}

void	PhoneBook::search(void) {
	std::string	inputLine;
	long		nb(~0);
	bool		validInput = false;

	if (!_contactCnt) {
		std::cout << "PHONEBOOK IS EMPTY" << std::endl;
		return ;
	}
	std::cout << formatField("ID") << '|';
	std::cout << formatField("FIRST NAME") << '|';
	std::cout << formatField("LAST NAME") << '|';
	std::cout << formatField("NICKNAME") << std::endl;
	for (unsigned i = 0; i < _contactCnt; ++i) {
		std::cout << formatField(i) << '|';
		std::cout << formatField(_contact[i].firstName) << '|';
		std::cout << formatField(_contact[i].lastName) << '|';
		std::cout << formatField(_contact[i].nickname) << std::endl;
	}
	while (!validInput) {
		std::cout << "ENTER A NUMBER (ID): ";
		std::getline(std::cin, inputLine);
		string_iterator	it = inputLine.begin();
		char			*ptr;

		errno = 0;
		if (!std::isdigit(*it) || (nb = strtol(inputLine.c_str(), &ptr, 0)) < 0
		|| errno == ERANGE || *ptr || nb >= _contactCnt)
			std::cerr << "INVALID INPUT" << std::endl;
		else validInput = true;
	}
	std::cout << "FIRST NAME: " << _contact[nb].firstName << std::endl;
	std::cout << "LAST NAME: " << _contact[nb].lastName << std::endl;
	std::cout << "NICKNAME: " << _contact[nb].nickname << std::endl;
	std::cout << "PHONE NUMBER: " << _contact[nb].phoneNumber << std::endl;
	std::cout << "DARKEST SECRET: " << _contact[nb].darkestSecret << std::endl;
}

void	PhoneBook::execute(const std::string &cmd) {
	if (cmd == "ADD") add();
	else if (cmd == "SEARCH") search();
	else if (cmd == "EXIT") std::exit(EXIT_SUCCESS);
}
