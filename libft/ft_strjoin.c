/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:55:40 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/22 17:28:25 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcpy(char *dst, const char *src)
{
	char	*tmp;

	tmp = dst;
	while (*src)
		*(dst++) = *(src++);
	*dst = 0;
	return (tmp);
}

static char		*ft_strcat(char *s1, const char *s2)
{
	char	*tmp;

	tmp = s1;
	while (*s1)
		s1++;
	ft_strcpy(s1, s2);
	return (tmp);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strcpy(tmp, s1);
	return (ft_strcat(tmp, s2));
}
