/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:33:58 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/16 22:33:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char		*ft_strlcpy(char *dst, const char *src, int len)
{
	if (!*src || !len)
	{
		*dst = 0;
		return (dst);
	}
	*dst = *src;
	return (ft_strlcpy(dst + 1, src + 1, len - 1) - 1);
}

char			*ft_strndup(const char *str, int n)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	return (ft_strlcpy(tmp, str, n));
}

static t_bool	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\r'
	|| c == '\v' || c == '\f' || c == ' ')
		return (true);
	return (false);
}

int				ft_atoi(const char *str)
{
	long	nb;
	long	neg;

	nb = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if (*str == '+')
	{
		if (neg < 0)
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
	{
		nb = 10 * nb + (int)*str - 48;
		str++;
	}
	return ((int)(neg * nb));
}
