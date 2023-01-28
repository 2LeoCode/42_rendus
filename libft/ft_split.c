/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:48:01 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/20 21:25:21 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcdup(const char *s, int c)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	tmp2 = (char*)s;
	len = 0;
	while (*tmp2 && (*(tmp2++) != c))
		len++;
	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(tmp, s, len + 1);
	return (tmp);
}

static int		splitsize(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		len += (*s != 0);
		while (*s && (*s - c))
			s++;
	}
	return (len + !c);
}

static int		splitfill(char **split, const char *s, char c)
{
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && !(*(split++) = ft_strcdup((char*)s, c)))
			return (-1);
		while (*s && (*s - c))
			s++;
	}
	*split = NULL;
	return (0);
}

static char		**free_failure(char **to_free)
{
	while (*to_free)
	{
		free(*to_free);
		*(to_free++) = NULL;
	}
	free(to_free);
	to_free = NULL;
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * (splitsize(s, c) + 1))))
		return (NULL);
	if (splitfill(split, s, c))
		return (free_failure(split));
	return (split);
}
