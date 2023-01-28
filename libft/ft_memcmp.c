/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:22:02 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/20 17:27:58 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && (*((char*)s1++) == *((char*)s2++)))
		continue ;
	return (n ? (*((unsigned char*)(s1 - 1)) - *((unsigned char*)(s2 - 1)))
	: ((*((char*)s1) != *((char*)s2))
	* (*((unsigned char*)s1) - *((unsigned char*)s2))));
}
