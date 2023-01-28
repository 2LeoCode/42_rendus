/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:32:34 by crochu            #+#    #+#             */
/*   Updated: 2022/02/11 15:20:55 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <
	typename value_type,
	typename size_type,
	typename fun_type
> void	iter(value_type *arr, size_type size, fun_type function) {
	while (size--) function(arr[size]);
}
