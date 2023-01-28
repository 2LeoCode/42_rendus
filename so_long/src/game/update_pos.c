/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:48:58 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 17:00:35 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../mlx_rework/mlx_rework.h"
#include "../dprintf/dprintf.h"

static void	process_valid_pos(t_gamedata *sl, t_vec3 new_pos)
{
	static int	mov_cnt = 0;

	if (sl->map->data[new_pos.z][new_pos.y][new_pos.x] == 'C')
	{
		--sl->map->item_cnt;
		sl->map->data[new_pos.z][new_pos.y][new_pos.x] = '0';
	}
	else if (sl->map->data[new_pos.z][new_pos.y][new_pos.x] == 'E'
		&& !sl->map->item_cnt)
		ft_mlx_loop_end();
	sl->player = new_pos;
	sl->origin = sl_get_origin(sl->player);
	ft_dprintf(1, "\r\033[0K%d", ++mov_cnt);
	ft_dflush(1);
}

t_vec2	sl_get_origin(t_vec3 player)
{
	const t_vec2	center = {604, 324};
	t_vec2			origin;

	origin = center;
	while (player.x--)
	{
		origin.x -= X_OFFSET;
		origin.y -= Y_OFFSET;
	}
	while (player.y--)
	{
		origin.y -= Y_OFFSET;
		origin.x += X_OFFSET;
	}
	while (player.z--)
		origin.y += Z_OFFSET;
	return (origin);
}

void	check_new_pos(t_gamedata *sl, t_vec3 new_pos)
{
	if ((sl->player.x != new_pos.x || sl->player.y != new_pos.y)
		&& sl->map->data[new_pos.z][new_pos.y][new_pos.x] != '1'
		&& (sl->map->z <= new_pos.z + 2 ||
			sl->map->data[new_pos.z + 2][new_pos.y][new_pos.x] == '1')
		&& (sl->map->z <= new_pos.z + 1 ||
			sl->map->data[new_pos.z + 1][new_pos.y][new_pos.x] == '1'))
		process_valid_pos(sl, new_pos);
}

void	sl_update_pos(t_gamedata *sl, int pos)
{
	static int	pos_data[4] = {STEVE_BACK, STEVE_BACK_2, STEVE, STEVE_2};
	static int	next_x_coord[4] = {0, -1, 0, 1};
	static int	next_y_coord[4] = {-1, 0, 1, 0};
	t_vec3		new_pos;

	new_pos = sl->player;
	sl->player_texture = pos_data[pos];
	new_pos.x += next_x_coord[pos];
	new_pos.y += next_y_coord[pos];
	if (sl->map->z > sl->player.z + 1
		&& sl->map->data[sl->player.z + 1][new_pos.y][new_pos.x] != '1'
		&& (sl->map->z <= sl->player.z + 3 ||
			sl->map->data[sl->player.z + 3][sl->player.y][sl->player.x] == '1'))
		++new_pos.z;
	else if (sl->player.z > 0
		&& sl->map->data[sl->player.z][new_pos.y][new_pos.x] == '1'
		&& sl->map->data[sl->player.z - 1][new_pos.y][new_pos.x] != '1'
		&& (sl->map->z <= sl->player.z + 2 ||
			sl->map->data[sl->player.z + 2][new_pos.y][new_pos.x] == '1'))
		--new_pos.z;
	check_new_pos(sl, new_pos);
}
