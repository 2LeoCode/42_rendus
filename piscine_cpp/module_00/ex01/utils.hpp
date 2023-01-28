/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:09:08 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/18 18:44:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>

namespace ft {
	template <
		class InputIt,
		class UnaryFunction
	> InputIt	advance_while(InputIt &start, InputIt limit, UnaryFunction f) {
		while (start != limit && f(*start)) ++start;
		return start;
	}

	bool	is_space(const char &c) { return std::isspace(c); }
	bool	is_name(const char &c) { return std::isalpha(c) || c == '-'; }
	bool	is_alpha(const char &c) { return std::isalpha(c); }
}
