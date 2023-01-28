/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:16:08 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:33:34 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dprintf_int.h"
#include <unistd.h>

t_buffer	*dprintf_buffer(int fd)
{
	static t_buffer	buf[DPRINTF_FD_LIMIT + 1] = {0};

	return (buf + fd);
}

void	buffer_add(int fd, char c)
{
	t_buffer *const	buf = dprintf_buffer(fd);

	buf->data[buf->pos++] = c;
	if (buf->pos == DPRINTF_BUFFER_SIZE
		|| buf->data[buf->pos - 1] == '\n')
	{
		write(fd, buf->data, buf->pos);
		buf->pos = 0;
	}
}
