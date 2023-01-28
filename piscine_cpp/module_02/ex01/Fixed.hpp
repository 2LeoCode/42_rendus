/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:48:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 00:14:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int value);
		Fixed(const float value);

		~Fixed();

		Fixed	&operator =(const Fixed src);

		int		getRawBits(void) const;
		void	setRawBits(int rawBits);
		int		getNbBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		static const int	_nbBits;
		int					_rawBits;
};

std::ostream	&operator <<(std::ostream &out, const Fixed &nb);
