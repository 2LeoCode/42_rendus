/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dflush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:49:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/04 18:12:22 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dprintf_int.h"
#include <unistd.h>

int	ft_dflush(int fd)
{
	write(fd, dprintf_buffer(fd)->data, dprintf_buffer(fd)->pos);
	dprintf_buffer(fd)->pos = 0;
	return (0);
}
