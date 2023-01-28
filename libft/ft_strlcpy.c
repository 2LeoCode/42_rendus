/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:23:36 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/20 01:18:13 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		len;

	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	while (*src && (dstsize-- > 1))
		*(dst++) = *(src++);
	*dst = 0;
	return (len);
}
