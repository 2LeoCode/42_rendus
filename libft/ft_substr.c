/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:33:56 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/22 17:27:49 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndup(const char *s1, size_t n)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strlcpy(tmp, s1, n + 1);
	return (tmp);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	while (s && start-- && *s)
		s++;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	return (ft_strndup(s, (size > len) ? len : size));
}
