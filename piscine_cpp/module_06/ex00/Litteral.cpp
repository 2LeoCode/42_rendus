/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:54:51 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 16:12:33 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Litteral.hpp"

#include <iostream>
#include <iomanip>

#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cstring>
#include <cmath>

namespace ft {
	typedef std::string::const_iterator	const_iterator;


	bool isValidInt(const std::string &s) {
		const_iterator it = s.begin();
	
		if (*it == '+' || *it == '-')
			++it;
		if (it == s.end())
			return false;
		while (isdigit(*it))
			++it;
		return (it == s.end());
	}

	bool isValidFloat(const std::string &s) {
		const_iterator it = s.begin();
		bool dot;

		if (!s.compare("nan") || !s.compare("nanf") || !s.compare("inf")
		|| !s.compare("inff") || !s.compare("+inf") || !s.compare("+inff")
		|| !s.compare("-inf") || !s.compare("-inff"))
			return true;
		if (*it == '+' || *it == '-')
			++it;
		if (it == s.end()) return false;
		if ((dot = *it == '.'))
			++it;
		if (!isdigit(*it)) return false;
		while (isdigit(*it)) ++it;
		if (*it == '.') {
			if (dot)
				return false;
			++it;
		}
		while (isdigit(*it)) ++it;
		if ((*it == 'e' || *it == 'E') && (++it == s.end()
		|| ((*it == '-' || *it == '+') && ++it == s.end())))
			return false;
		while (isdigit(*it))
			++it;
		if (*it == 'f' || *it == 'F')
			++it;
		return (it == s.end());
	}

	bool isValidChar(const std::string &s) {
		return s.length() == 1 && isprint(*s.c_str());
	}
}

Litteral::Litteral(std::string s) {
	errno = 0;
	if (ft::isValidInt(s)) {
		long tmp = strtol(s.c_str(), NULL, 0);
		if (errno == ERANGE || tmp < INT_MIN || tmp > INT_MAX)
			throw ETooLargeNumber();
		_data.i = tmp;
		_type = Int;
	} else if (ft::isValidFloat(s)) {
		_data.f = strtof(s.c_str(), NULL);
		if (errno == ERANGE) {
			if (*s.rbegin() == 'f' || *s.rbegin() == 'F')
				throw ETooLargeNumber();
			errno = 0;
			_data.d = strtod(s.c_str(), NULL);
			if (errno == ERANGE) throw ETooLargeNumber();
			_type = Double;
		} else _type = Float;
	} else if (ft::isValidChar(s)) {
		_data.c = *s.c_str();
		_type = Char;
	} else throw EInvalidLitteral();
}

Litteral::Litteral(const Litteral &other) : _type(other._type), _data(other._data) { }

Litteral::~Litteral() { }


Litteral &Litteral::operator=(const Litteral &other) {
	_type = other._type;
	_data = other._data;
	return *this;
}

Litteral &Litteral::operator=(const std::string s) {
	bzero(&_data, sizeof(_data));
	errno = 0;
	if (ft::isValidInt(s)) {
		long tmp = strtol(s.c_str(), NULL, 0);
		if (errno == ERANGE || tmp < INT_MIN || tmp > INT_MAX)
			throw ETooLargeNumber();
		_data.i = tmp;
		_type = Int;
	} else if (ft::isValidFloat(s)) {
		_data.f = strtof(s.c_str(), NULL);
		if (errno == ERANGE) {
			if (*s.rbegin() == 'f' || *s.rbegin() == 'F')
				throw ETooLargeNumber();
			errno = 0;
			_data.d = strtod(s.c_str(), NULL);
			if (errno == ERANGE) throw ETooLargeNumber();
			_type = Double;
		} else _type = Float;
	} else if (ft::isValidChar(s)) {
		_data.c = *s.c_str();
		_type = Char;
	} else throw EInvalidLitteral();
	return *this;
}

Litteral::Type Litteral::getType(void) const {
	return _type;
} 

char Litteral::getChar(void) const {
	switch (_type) {
		case Int: return static_cast< char >(_data.i);
		case Float: return static_cast< char >(_data.f);
		case Double: return static_cast< char >(_data.d);
		case Char: break ;
	}
	return _data.c;
}

int Litteral::getInt(void) const {
	switch (_type) {
		case Char: return static_cast< int >(_data.c);
		case Float: return static_cast< int >(_data.f);
		case Double: return static_cast< int >(_data.d);
		case Int: break ;
	}
	return _data.i;
}

float Litteral::getFloat(void) const {
	switch (_type) {
		case Char: return static_cast< float >(_data.c);
		case Int: return static_cast< float >(_data.i);
		case Double: return static_cast< float >(_data.d);
		case Float: break ;
	}
	return _data.f;
}

double Litteral::getDouble(void) const {
	switch (_type) {
		case Char: return static_cast< double >(_data.c);
		case Int: return static_cast< double >(_data.i);
		case Float: return static_cast< double >(_data.f);
		case Double: break ;
	}
	return _data.d;
}

void Litteral::print(void) const {
	char	c(getChar());
	int		i(getInt());
	float	f(getFloat());
	double	d(getDouble());

	switch (_type) {
		case Char:
			std::cout << "char: ";
			if (!isprint(c))
				std::cout << "Non displayable";
			else std::cout << '\'' << c << '\'';
			std::cout << std::endl << "int: " << i << std::endl <<
				"float: " << f << std::endl <<
				"double: " << d << std::endl;
			break ;
		case Int:
			std::cout << "char: ";
			if (i != c)
				std::cout << "impossible";
			else if (!isprint(c))
				std::cout << "Non displayable";
			else std::cout << '\'' << c << '\'';
			std::cout << std::endl << "int: " << i << std::endl <<
				"float: " << f << std::endl <<
				"double: " << d << std::endl;
			break ;
		case Float:
			std::cout << "char: ";
			if (f > CHAR_MAX || f < CHAR_MIN)
				std::cout << "impossible";
			else if (!isprint(c))
				std::cout << "Non displayable";
			else std::cout << '\'' << c << '\'';
			std::cout << std::endl << "int: ";
			if (isnanf(f) || isinff(f)
			|| f > static_cast< float >(INT_MAX)
			|| f < static_cast< float >(INT_MIN))
				std::cout << "impossible";
			else std::cout << i;
			std::cout << std::endl << "float: " << f << 'f' << std::endl <<
				"double: " << d << std::endl;
			break ;
		case Double:
			std::cout << "char: ";
			if (d > CHAR_MAX || d < CHAR_MIN)
				std::cout << "impossible";
			else if (!isprint(c))
				std::cout << "Non displayable";
			else std::cout << '\'' << c << '\'';
			std::cout << std::endl << "int: ";
			if (std::isnan(d) || std::isinf(d)
			|| d > static_cast< double >(INT_MAX)
			|| d < static_cast< double >(INT_MIN))
				std::cout << "impossible";
			else std::cout << i;
			std::cout << std::endl << "float: " << f << 'f' << std::endl <<
				"double: " << d << std::endl;
	}
}

const char *Litteral::EInvalidLitteral::what(void) const throw () {
	return "Invalid litteral";
}

const char *Litteral::ETooLargeNumber::what(void) const throw () {
	return "Too large number";
}
