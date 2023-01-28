/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:10:01 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:29:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/game.h"
#include "../memory/memory.h"
#include "parsing_int.h"

void	expect(char expected, char got)
{
	if (expected != got)
		invalid_argument();
}

void	expect_horizontal_walls(t_map *map, int x, int z)
{
	expect('1', map->data[z][0][x]);
	expect('1', map->data[z][map->y - 1][x]);
}

void	expect_vertical_walls(t_map *map, int y, int z)
{
	expect('1', map->data[z][y][0]);
	expect('1', map->data[z][y][map->x - 1]);
}
