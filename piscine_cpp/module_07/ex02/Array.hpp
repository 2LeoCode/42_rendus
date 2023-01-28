/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:41:18 by crochu            #+#    #+#             */
/*   Updated: 2022/02/11 15:55:09 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.hpp"
#include <cstring>
#include <iostream>
#include <cstddef>

template <
	class T
> class Array {
	public:
		Array(std::size_t size = 0) : m_size(size), m_data(new T[size]) { }
		~Array() { delete[] m_data; }

		Array(const Array &other) :
		m_size(other.m_size), m_data(new T[m_size]) {
			ft::copy(other.m_data, other.m_data + m_size, m_data);
		}

		Array	&operator =(const Array &other) {
			m_size = other.m_size;
			delete[] m_data;
			m_data = new T[m_size];
			ft::copy(other.m_data, other.m_data + m_size, m_data);
			return *this;
		}
		T			&operator [](unsigned i) {
			if (i >= m_size) throw EOutOfBounds();
			return m_data[i];
		}
		const T		&operator [](unsigned i) const {
			if (i >= m_size) throw EOutOfBounds();
			return m_data[i];
		}

		std::size_t	size(void) const { return m_size; }
		void		print(void) const {
			std::cout << std::endl;
		}

		struct EOutOfBounds : public std::exception {
			const char *what() const throw() { return "Out of bounds"; }
		};

	private:
		std::size_t	m_size;
		T*			m_data;
};

template <
	class T
> std::ostream	&operator <<(std::ostream &out, const Array< T > &arr) {
	for (unsigned i = 0; i < arr.size(); ++i)
		out << '[' << arr[i] << ']';
	return out;
}
