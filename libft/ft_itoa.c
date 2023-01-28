/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 23:20:51 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/18 22:21:26 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_abs(long n)
{
	return ((n < 0) ? -n : n);
}

static void		ft_placenbr(long nb, char *s, int size)
{
	if (nb < 0)
		*s = '-';
	s[size + (nb < 0)] = 0;
	while (size--)
	{
		s[size + (nb < 0)] = ft_abs(nb % 10) + 48;
		nb /= 10;
	}
}

static int		ft_nbrsize(int n)
{
	return (n ? (1 + ft_nbrsize(n / 10)) : 0);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (!(size = ft_nbrsize(n)))
		size = 1;
	if (!(str = malloc(sizeof(char) * (size + (n < 0) + 1))))
		return (NULL);
	ft_placenbr((long)n, str, size);
	return (str);
}
