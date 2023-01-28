/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:21:03 by crochu            #+#    #+#             */
/*   Updated: 2022/02/11 15:25:28 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <
	class T
> void	swap(T &a ,T &b) {
	const T tmp = a;

	a = b;
	b = tmp;
}

template <
	class T
> T	min(T a, T b) { return b < a ? b : a; }

template <
	class T
> T	max(T a, T b) { return b > a ? b : a; }
