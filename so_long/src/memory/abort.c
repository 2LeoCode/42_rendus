/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:15:03 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:12:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dprintf/dprintf.h"
#include "../memory/memory.h"

#include <string.h>
#include <errno.h>
#include <stdlib.h>

void	invalid_argument(void)
{
	errno = EINVAL;
	ft_abort();
}

void	ft_abort(void)
{
	ft_dprintf(2, "Error: %s\n", strerror(errno));
	clear_memory();
	exit(EXIT_FAILURE);
}
