/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniquePtr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:02:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 16:47:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template < typename T >
class UniquePtr {
	public:
		UniquePtr() : m_ptr(NULL) { }
		~UniquePtr() { delete m_ptr; }

		UniquePtr(const UniquePtr &other)
		:	m_ptr(const_cast< UniquePtr& >(other).m_ptr) { }
		UniquePtr(T *ptr) : m_ptr(ptr) { }

		UniquePtr	&operator =(const UniquePtr &other) {
			m_ptr = const_cast< UniquePtr& >(other).m_ptr;
			return *this;
		}
		UniquePtr	&operator =(T *ptr) {
			m_ptr = ptr;
			return *this;
		}

		T			&operator *(void) { return *m_ptr; }
		T			*operator ->(void) { return m_ptr; }

	private:
		T	*m_ptr;
};
