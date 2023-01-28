/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniqueArrayPtr.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:42:09 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 14:59:45 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <
	typename T
> class UniqueArrayPtr {
	public:

	UniqueArrayPtr() : _ptr(NULL) { }
	~UniqueArrayPtr() {
		delete[] _ptr;
	}
	UniqueArrayPtr(T *ptr) : _ptr(ptr) { }
	UniqueArrayPtr(const UniqueArrayPtr &other) : _ptr(other._ptr) { }

	UniqueArrayPtr	&operator=(const UniqueArrayPtr &other) {
		_ptr = other._ptr;
		return (*this);
	}
	UniqueArrayPtr	&operator=(T *ptr) {
		_ptr = ptr;
		return (*this);
	}
	T			&operator*(void) {
		return *_ptr;
	}
	T			*operator->(void) {
		return _ptr;
	}
	T			&operator[](size_t i) {
		return _ptr[i];
	}

	private:

	T	*_ptr;
};
