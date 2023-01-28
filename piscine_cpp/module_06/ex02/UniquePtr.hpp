/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniquePtr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:58:16 by crochu            #+#    #+#             */
/*   Updated: 2022/01/27 11:09:33 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

template <typename T>
class UniquePtr {
	public:
		UniquePtr(T *ptr = NULL) : m_ptr(ptr) { }
		UniquePtr(const UniquePtr &other) 
		:	m_ptr(const_cast< UniquePtr& >(other).m_ptr)
		{ }
		~UniquePtr() { delete m_ptr; }

		UniquePtr &operator =(const UniquePtr &other) {
			m_ptr = const_cast< UniquePtr& >(other).m_ptr;
			return *this;
		}
		UniquePtr &operator =(T *ptr) {
			m_ptr = ptr;
			return *this;
		}
		T *operator->(void) { return m_ptr; }
		T &operator*(void) { return *m_ptr; }

	private:
		T *m_ptr;
};
