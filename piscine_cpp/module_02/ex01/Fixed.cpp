/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:55:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 17:31:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <sstream>

#include <cmath>
#include <climits>
#include <cstring>
#include <endian.h>

#define ABS(x) (((x) < 0) ? -(x) : (x))

#define PRINT_BITS(var) do {\
	for (unsigned i = sizeof(var) * 8 - 1; i != UINT_MAX; --i) {\
		if (i && (i + 1) != sizeof(var) * 8 && !((i + 1) % 4))\
			std::cout << ' ';\
		std::cout << !!((var) & (1 << i));\
	}\
	std::cout << std::endl;\
} while (0)

const int	Fixed::_nbBits = 8;

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _rawBits(src._rawBits) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "int constructor called" << std::endl;
	if (BYTE_ORDER == LITTLE_ENDIAN)
		_rawBits = (value << _nbBits);
	else
		_rawBits = (value >> _nbBits);
}

Fixed::Fixed(const float value) {
	std::cout << "float constructor called" << std::endl;
	if (BYTE_ORDER == LITTLE_ENDIAN)
		_rawBits = roundf(value * (1 << _nbBits));
	else
		_rawBits = roundf(value * (1 >> _nbBits));
}

Fixed	&Fixed::operator =(const Fixed src) {
	std::cout << "Assignation operator called" << std::endl;
	_rawBits = src._rawBits;
	return *this;
}

std::ostream	&operator <<(std::ostream &out, const Fixed &nb) {
	out << nb.toFloat();
	return out;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits(int rawBits) {
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = rawBits;
}

int	Fixed::getNbBits(void) const { return _nbBits; }

int	Fixed::toInt(void) const {
	if (BYTE_ORDER == LITTLE_ENDIAN)
		return _rawBits >> _nbBits;
	return _rawBits << _nbBits;
}

float	Fixed::toFloat(void) const {
	if (BYTE_ORDER == LITTLE_ENDIAN)
		return static_cast<float>(_rawBits) / (1 << _nbBits);
	return static_cast<float>(_rawBits) / (1 >> _nbBits);
}
