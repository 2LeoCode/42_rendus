/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:21:01 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/18 22:51:14 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\n' || c == '\t' || c == '\r'
	|| c == '\f' || c == '\v' || c == ' ');
}

int			ft_atoi(const char *str)
{
	long	nb;
	long	neg;

	nb = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (((*str == '-') || (*str == '+')) && (*(str++) == '-'))
		neg = -1;
	while (ft_isdigit(*str))
		nb = 10 * nb - 48 + (int)*(str++);
	return ((int)(neg * nb));
}
