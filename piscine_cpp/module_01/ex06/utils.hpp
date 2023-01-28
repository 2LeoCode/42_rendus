/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:26:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 15:29:39 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	template <
		class ForwardIt,
		class T
	> void	fill(ForwardIt first, ForwardIt last, const T &value) {
		while (first != last)
			*first++ = value;
	}
}
