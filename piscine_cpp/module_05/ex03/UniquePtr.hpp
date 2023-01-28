/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniquePtr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:47:33 by crochu            #+#    #+#             */
/*   Updated: 2021/11/03 00:53:23 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIQUEPTR_HPP
# define UNIQUEPTR_HPP

template < typename T >
class UniquePtr {
	public:

	UniquePtr(T *ptr = NULL) : _ptr(ptr) { }
	~UniquePtr() { delete _ptr; }

	UniquePtr(const UniquePtr &other) : _ptr(other._ptr) { }

	UniquePtr	&operator=(UniquePtr &other) {
		_ptr = other._ptr;
		return *this;
	}
	UniquePtr	&operator=(T *ptr) {
		_ptr = ptr;
		return *this;
	}
	T			&operator*(void) {
		return *_ptr;
	}
	T			*operator->(void) {
		return _ptr;
	}

	T	*ptr(void) {
		return _ptr;
	}


	private:

	T *_ptr;
};

#endif
