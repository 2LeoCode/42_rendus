/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:33:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/07 23:30:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../string/string.h"

#define SWAP_BUFSIZE 1024

void	ft_swap(void *a, void *b, size_t size)
{
	static char	buf[SWAP_BUFSIZE];

	if (size > SWAP_BUFSIZE)
	{
		ft_swap(a + SWAP_BUFSIZE, b + SWAP_BUFSIZE, size - SWAP_BUFSIZE);
		size = SWAP_BUFSIZE;
	}
	ft_memcpy(buf, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, buf, size);
}
