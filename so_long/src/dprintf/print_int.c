/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:46:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:35:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dprintf_int.h"

static int	print_int_r(int fd, long nb)
{
	int	ret;

	ret = 0;
	if (nb < 0)
	{
		buffer_add(fd, '-');
		nb = -nb;
		ret = 1;
	}
	if (nb < 10)
	{
		buffer_add(fd, nb + '0');
		ret = 1;
	}
	else
		ret += print_int_r(fd, nb / 10) + print_int_r(fd, nb % 10);
	return (ret);
}

int	print_int(int fd, va_list *ap)
{
	return (print_int_r(fd, va_arg(*ap, int)));
}
