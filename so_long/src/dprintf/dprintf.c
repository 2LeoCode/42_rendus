/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:12:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/04 17:43:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dprintf_int.h"
#include <unistd.h>

int	ft_dprintf(int fd, const char *fmt, ...)
{
	int		cnt;
	va_list	ap;

	cnt = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			cnt += print_arg(*++fmt)(fd, &ap);
		else
		{
			buffer_add(fd, *fmt);
			++cnt;
		}
		++fmt;
	}
	va_end(ap);
	return (cnt);
}
