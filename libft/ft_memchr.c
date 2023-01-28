/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:21:59 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/21 15:25:10 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!n)
		return (NULL);
	while (--n && (*((unsigned char*)s) != (unsigned char)c))
		s++;
	return ((*((unsigned char*)s) == (unsigned char)c) ? (void*)s : NULL);
}
