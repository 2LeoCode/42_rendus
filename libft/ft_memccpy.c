/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:21:56 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/19 20:18:46 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (n--)
		*((char*)dst++) = *((char*)src++);
	while ((n + 1) && n--
	&& (*((unsigned char*)(src - 1)) != (unsigned char)c))
		*((char*)dst++) = *((char*)src++);
	return ((*((unsigned char*)(src - 1)) == (unsigned char)c)
	? dst : NULL);
}
