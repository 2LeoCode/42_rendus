/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:51:05 by crochu            #+#    #+#             */
/*   Updated: 2022/02/12 20:38:26 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template <
	class T,
	class Container = std::deque< T >
> class MutantStack : public std::stack< T, Container > {
	public:
		typedef std::stack< T, Container >				stack_type;
		typedef typename Container::iterator 			iterator;
		typedef typename Container::const_iterator		const_iterator;
		typedef typename Container::reverse_iterator	reverse_iterator;
		typedef
		typename Container::const_reverse_iterator		const_reverse_iterator;

		MutantStack() : stack_type() { }
		~MutantStack() { }

		MutantStack		&operator =(const MutantStack &other) {
			stack_type::c = other.stack_type::c;
			return *this;
		}

		iterator		begin(void) { return stack_type::c.begin(); }
		const_iterator	begin(void) const { return stack_type::c.begin(); }
		iterator		end(void) { return stack_type::c.end(); }
		const_iterator	end(void) const { return stack_type::c.end(); }

		reverse_iterator		rbegin(void) { return stack_type::c.rbegin(); }
		const_reverse_iterator	rbegin(void) const
		{ return stack_type::c.rbegin(); }
		reverse_iterator		rend(void) { return stack_type::c.rend(); }
		const_reverse_iterator	rend(void) const
		{ return stack_type::c.rend(); }
};
