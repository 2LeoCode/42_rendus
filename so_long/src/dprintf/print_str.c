/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:46:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/04 17:34:23 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dprintf_int.h"
#include "../string/string.h"

int	print_str(int fd, va_list *ap)
{
	const char	*str = va_arg(*ap, char *);
	int			cnt;

	cnt = 0;
	while (*str)
	{
		buffer_add(fd, *str++);
		++cnt;
	}
	return (cnt);
}
