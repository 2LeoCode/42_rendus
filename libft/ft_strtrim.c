/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 19:18:57 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/22 17:23:40 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndup(const char *s, int n)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strlcpy(tmp, s, n + 1);
	return (tmp);
}

static int		trimsize(char const *str, char const *set)
{
	int len;

	len = ft_strlen(str);
	while (*str && ft_strchr(set, str[len - 1]))
		len--;
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	trim = ft_strndup(s1, trimsize(s1, set));
	return (trim);
}
