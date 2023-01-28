/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:24:16 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/20 03:28:22 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;

	size = ft_strlen(needle);
	if (!*needle)
		return ((char*)haystack);
	while (*haystack++ && (size <= len) && len--)
		if (!ft_strncmp(haystack - 1, needle, size))
			return ((char*)(haystack - 1));
	return (NULL);
}
