/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:46:30 by crochu            #+#    #+#             */
/*   Updated: 2022/02/10 14:22:12 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Litteral {
	public:
		enum Type {
			Char,
			Int,
			Float,
			Double
		};

		Litteral(std::string s = "0");
		Litteral(const Litteral &other);
		~Litteral();

		Litteral &operator=(const Litteral &other);
		Litteral &operator=(const std::string s);

		Type getType(void) const;
		char getChar(void) const;
		int getInt(void) const;
		float getFloat(void) const;
		double getDouble(void) const;

		void print(void) const;

		struct EInvalidLitteral : public std::exception {
			virtual const char *what(void) const throw ();
		};
		struct ETooLargeNumber : public std::exception {
			virtual const char *what(void) const throw ();
		};

	private:
		Type	_type;
		union {
			char	c;
			int		i;
			float	f;
			double	d;
		}		_data;
};
