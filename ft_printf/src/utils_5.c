/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:24:44 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/22 01:29:14 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void				ft_placenbr_u(unsigned long nb, char *s, int size)
{
	s[size] = 0;
	while (size--)
	{
		s[size] = nb % 10 + 48;
		nb /= 10;
	}
}

static unsigned int		ft_nbrsize_u(unsigned int n)
{
	return (n ? (1 + ft_nbrsize_u(n / 10)) : 0);
}

char					*ft_uitoa(unsigned int n)
{
	char	*str;
	int		size;

	if (!(size = ft_nbrsize_u(n)))
		size = 1;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_placenbr_u((unsigned long)n, str, size);
	return (str);
}
