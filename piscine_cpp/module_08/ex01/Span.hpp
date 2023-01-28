/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:57:39 by crochu            #+#    #+#             */
/*   Updated: 2022/02/12 20:04:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <algorithm>
#include <iterator>

class Span {
	public:
		Span(unsigned N = 0);
		Span(const Span &other);

		template <
			class InputIt
		> Span(InputIt first, InputIt last)
		:	m_size(std::distance(first, last)),
			m_cap(m_size),
			m_data(new int[m_cap]) {
				std::copy(first, last, m_data);
		}

		~Span();

		Span	&operator =(const Span &other);
		void	addNumber(int n);
		template <
			class InputIt
		> void	addNumbers(InputIt first, InputIt last) {
			const size_t	dist = std::distance(first, last);

			if (dist > m_cap) throw ESpanFull();
			std::copy(first, last, m_data);
			m_size = dist;
		}

		unsigned shortestSpan(void) const;
		unsigned longestSpan(void) const;

		unsigned	size(void) const;
		const int	*begin(void) const;
		const int	*end(void) const;

		struct ESpanFull : public std::exception {
			const char *what() const throw ();
		};
		struct ENoSpan : public std::exception {
			const char *what() const throw ();
		};

	private:
		unsigned	m_size;
		unsigned	m_cap;
		int			*m_data;
};

std::ostream &operator <<(std::ostream &, const Span &);
