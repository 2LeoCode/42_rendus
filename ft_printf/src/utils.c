/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:07:02 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/16 19:42:12 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_strchr(const char *str, int c)
{
	if (!str || !*str)
		return (c ? NULL : (char*)str);
	if (*str == c)
		return ((char*)str);
	return (ft_strchr(str + 1, c));
}

t_bool	ft_strfind(const char *str, const char *charset)
{
	char	*tmp;

	tmp = (char*)charset;
	if (!str || !*str)
		return (false);
	while (*tmp && *str != *tmp)
		tmp++;
	if (*tmp)
		return (true);
	return (ft_strfind(str + 1, charset));
}

size_t	ft_strlen(const char *str)
{
	return (*str ? (1 + ft_strlen(str + 1)) : 0);
}

t_bool	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

t_bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
