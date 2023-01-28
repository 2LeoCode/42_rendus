/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:06:37 by lsuardi           #+#    #+#             */
/*   Updated: 2022/02/11 15:34:48 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	template <
		class InputIt,
		class OutputIt
	> OutputIt	copy(InputIt first, InputIt last, OutputIt d_first) {
		while (first != last)
			*d_first++ = *first++;
		return d_first;
	}
};
