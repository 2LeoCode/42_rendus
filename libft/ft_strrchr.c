/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:22:29 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/20 17:41:46 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	if (!*s && !c)
		return ((char*)s);
	while (*s && ft_strchr(s, c))
		s++;
	if (s - tmp)
		return (c ? (char*)(s - 1) : (char*)s);
	return (NULL);
}
