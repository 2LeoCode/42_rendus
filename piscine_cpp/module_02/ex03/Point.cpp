/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:24:58 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 17:45:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) { }

Point::~Point() { }

Point::Point(const Point &other) : _x(other._x), _y(other._y) { }

Point::Point(const float x, const float y) : _x(x), _y(y) { }

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) { }

Point	&Point::operator =(const Point &other) {
	(void)other;
	return *this;
}

bool	operator ==(const Point &a, const Point &b) {
	return a.x() == b.x() && a.y() == b.y();
}

const Fixed	&Point::x(void) const { return _x; }

const Fixed	&Point::y(void) const { return _y; }
