/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniquePtr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:19:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 13:33:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <
	typename T
> class UniquePtr {
	public:
		UniquePtr() : _ptr(NULL) { }
		UniquePtr(T *ptr) : _ptr(ptr) { }
		UniquePtr(const UniquePtr &other) : _ptr(other._ptr) { }
		~UniquePtr() { delete _ptr; }

		UniquePtr	&operator=(const UniquePtr &other) {
			_ptr = other._ptr;
			return (*this);
		}
		UniquePtr	&operator=(T *ptr) {
			_ptr = ptr;
			return (*this);
		}

		T			&operator*(void) { return *_ptr; }
		T			*operator->(void) { return _ptr; }

	private:
		T	*_ptr;
};
