/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:34:01 by crochu            #+#    #+#             */
/*   Updated: 2022/02/12 20:31:44 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <algorithm>

template <
	class T
> int	&easyfind(T &cont, int value) {
	typename T::iterator	found;

	if ((found = std::find(cont.begin(), cont.end(), value)) == cont.end())
		throw std::out_of_range("easyfind");
	return *found;
}
