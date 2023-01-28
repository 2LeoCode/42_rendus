/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:55:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 17:42:37 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <climits>
#include <iomanip>

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

Fixed::Fixed() : _rawBits(0) { }

Fixed::~Fixed() { }

Fixed::Fixed(const Fixed &src) : _rawBits(src._rawBits) { }

Fixed::Fixed(const int value) {
	if (BYTE_ORDER == LITTLE_ENDIAN)
		_rawBits = (value << _nbBits);
	else
		_rawBits = (value >> _nbBits);
}

Fixed::Fixed(const float value) {
	if (BYTE_ORDER == LITTLE_ENDIAN)
		_rawBits = roundf(value * (1 << _nbBits));
	else
		_rawBits = roundf(value * (1 >> _nbBits));
}

Fixed	&Fixed::operator =(const Fixed src) {
	_rawBits = src._rawBits;
	return *this;
}

Fixed	&Fixed::operator ++(void) {
	++_rawBits;
	return *this;
}

Fixed	Fixed::operator ++(int) {
	Fixed	ret(*this);

	++*this;
	return ret;
}

Fixed	&Fixed::operator --(void) {
	--_rawBits;
	return *this;
}

Fixed	Fixed::operator --(int) {
	Fixed	ret(*this);

	--*this;
	return ret;
}

int	Fixed::getRawBits(void) const { return _rawBits; }

void	Fixed::setRawBits(int rawBits) { _rawBits = rawBits; }

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

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return a < b ? b : a;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return a > b ? b : a;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) { return a < b ? b : a; }

Fixed	&Fixed::min(Fixed &a, Fixed &b) { return a > b ? b : a; }

std::ostream	&operator <<(std::ostream &out, const Fixed &nb) {
	out << nb.toFloat();
	return out;
}

bool	operator >(Fixed a, Fixed b) {
	return a.getRawBits() > b.getRawBits();
}

bool	operator ==(Fixed a, Fixed b) {
	return a.getRawBits() == b.getRawBits();
}

bool	operator <(Fixed a, Fixed b) { return !(a >= b); }

bool	operator >=(Fixed a, Fixed b) { return a == b || a > b; }

bool	operator <=(Fixed a, Fixed b) { return !(a > b); }

bool	operator !=(Fixed a, Fixed b) { return !(a == b); }

Fixed	operator +(Fixed a, Fixed b) {
	Fixed	ret;

	ret.setRawBits(a.getRawBits() + b.getRawBits());
	return ret;
}

Fixed	operator -(Fixed a, Fixed b) {
	Fixed	ret;


	ret.setRawBits(a.getRawBits() - b.getRawBits());
	return ret;
}

Fixed	operator *(Fixed a, Fixed b) {
	Fixed	ret;

	if (BYTE_ORDER == LITTLE_ENDIAN)
		ret.setRawBits((a.getRawBits() * b.getRawBits()) >> a.getNbBits());
	else
		ret.setRawBits((a.getRawBits() * b.getRawBits()) << a.getNbBits());
	return ret;
}

Fixed	operator /(Fixed a, Fixed b) {
	Fixed	ret;

	if (BYTE_ORDER == LITTLE_ENDIAN)
		ret.setRawBits((a.getRawBits() << a.getNbBits()) / b.getRawBits());
	else
		ret.setRawBits((a.getRawBits() >> a.getNbBits()) / b.getRawBits());
	return ret;
}
