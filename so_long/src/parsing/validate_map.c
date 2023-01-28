/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:07:13 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:53:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/game.h"
#include "../memory/memory.h"
#include "parsing_int.h"

static void	validate_player(int *check_mask, t_map *map, t_vec3 pos)
{
	if (*check_mask & PLAYER_MASK
		|| (map->z > pos.z + 2 && map->data[pos.z + 2][pos.y][pos.x] != '1')
		|| (map->z > pos.z + 1 && map->data[pos.z + 1][pos.y][pos.x] != '1'))
		invalid_argument();
	map->player_spawn = pos;
	*check_mask |= PLAYER_MASK;
}

static void	validate_item(int *check_mask, t_map *map, t_vec3 pos)
{
	if (map->z > pos.z + 1 && map->data[pos.z + 1][pos.y][pos.x] != '1')
		invalid_argument();
	++map->item_cnt;
	*check_mask |= ITEM_MASK;
}

static void	validate_exit(int *check_mask, t_map *map)
{
	++map->exit_cnt;
	*check_mask |= EXIT_MASK;
}

static void	validate_tile(int *check_mask, t_map *map, t_vec3 pos)
{
	if (map->data[pos.z][pos.y][pos.x] == 'P')
		validate_player(check_mask, map, pos);
	else if (map->data[pos.z][pos.y][pos.x] == 'C')
		validate_item(check_mask, map, pos);
	else if (map->data[pos.z][pos.y][pos.x] == 'E')
		validate_exit(check_mask, map);
	else if (map->data[pos.z][pos.y][pos.x] != '0'
		&& map->data[pos.z][pos.y][pos.x] != '1')
		invalid_argument();
}

void	validate_map(t_map *map)
{
	int	check_mask;
	int	i;
	int	j;
	int	k;

	i = -1;
	check_mask = 0;
	while (++i < map->z)
	{
		k = -1;
		while (++k < map->x)
			expect_horizontal_walls(map, k, i);
		j = 0;
		while (++j < map->y - 1)
		{
			expect_vertical_walls(map, j, i);
			k = 0;
			while (++k < map->x - 1)
				validate_tile(&check_mask, map, (t_vec3){k, j, i});
		}
	}
	if (!(check_mask & PLAYER_MASK
			&& check_mask & ITEM_MASK
			&& check_mask & EXIT_MASK))
		invalid_argument();
}
