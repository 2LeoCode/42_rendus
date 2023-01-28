/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:19:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/04 18:00:23 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dprintf_int.h"

int	print_char(int fd, va_list *ap)
{
	buffer_add(fd, va_arg(*ap, int));
	return (1);
}
