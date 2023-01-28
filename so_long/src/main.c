/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:38:31 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:22:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "string/string.h"
#include "dprintf/dprintf.h"
#include "memory/memory.h"
#include <unistd.h>
#include <X11/X.h>

int	main(int argc, char **argv)
{
	t_gamedata	so_long;

	if (argc != 2 || ft_memcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_dprintf(2, "usage: %s <file.ber>\n", argv[0]);
		return (1);
	}
	sl_init(&so_long, argv[1]);
	sl_run(&so_long);
	write(1, "\n", 1);
	clear_memory();
	return (0);
}
