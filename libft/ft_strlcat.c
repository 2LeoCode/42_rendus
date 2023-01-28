/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:23:31 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/20 01:23:01 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ((dstsize > ft_strlen(dst)) ? ft_strlen(dst) : dstsize);
	while (*(dst++))
		dstsize -= (dstsize > 0);
	return (len + ft_strlcpy(dst - 1, src, dstsize));
}
