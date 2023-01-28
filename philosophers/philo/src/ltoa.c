/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:29:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/14 18:29:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static unsigned int	ndigits(long n)
{
	unsigned int	cnt;

	cnt = !n;
	while (n)
	{
		n /= 10;
		++cnt;
	}
	return (cnt);
}

char	*ft_ltoa(char *s_ptr, long n)
{
	char			*endptr;

	if (n)
		*s_ptr = '-';
	else
		*s_ptr = '0';
	s_ptr += ndigits(n) + (n < 0);
	*s_ptr = 0;
	endptr = s_ptr;
	while (n)
	{
		*--s_ptr = '0' + ft_abs(n % 10);
		n /= 10;
	}
	return (endptr);
}
