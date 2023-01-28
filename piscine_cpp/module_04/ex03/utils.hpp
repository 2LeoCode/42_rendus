/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:48:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 23:19:30 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

	template < class InputIt, class OutputIt >
	OutputIt	copy(InputIt first, InputIt last, OutputIt d_first) {
		while (first != last)
			*d_first++ = *first++;
		return d_first;
	}

	template < class Iter, class T >
	Iter		fill(Iter first, Iter last, const T &value) {
		while (first != last)
			*first++ = value;
		return first;
	}

}
