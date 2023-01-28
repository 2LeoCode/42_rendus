/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_flush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:46:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:57:18 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../string/string.h"

static void	render_texture(t_gamedata *sl, int id, int x, int y)
{
	sl_image_to_window(&sl->window, &sl->textures[id], x, y);
}

static void	render_tile(t_gamedata *sl, int x, int y, int z)
{
	const int	rx = sl->origin.x + (x - y) * X_OFFSET;
	const int	ry = sl->origin.y + (x + y) * Y_OFFSET - z * Z_OFFSET;

	if (z + 1 == sl->map->z || y + 1 == sl->map->y || x + 1 == sl->map->x
		|| sl->map->data[z + 1][y][x] == '1'
		|| sl->map->data[z][y + 1][x] == '1'
		|| sl->map->data[z][y][x + 1] == '1')
	{
		if (sl->map->data[z][y][x] == 'E')
			render_texture(sl, BLOCK_OF_DIAMOND, rx, ry);
		else if (sl->map->data[z][y][x] == '1')
		{
			if (!z)
				render_texture(sl, LAVA, rx, ry);
		}
		else
			render_texture(sl, CHISELED_STONE_BRICKS, rx, ry);
	}
	if (sl->player.x == x && sl->player.y == y && sl->player.z == z)
		render_texture(sl, sl->player_texture,
			rx + PLAYER_X_OFFSET, ry - PLAYER_Y_OFFSET);
	else if (sl->map->data[z][y][x] == 'C')
		render_texture(sl, EMERALD, rx + ITEM_OFFSET, ry - ITEM_OFFSET);
}

void	sl_render_flush(t_gamedata *sl)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	ft_memset(sl->window.img.pixels, 0,
		sizeof(t_trgb) * sl->window.img.size_line * sl->window.img.h);
	while (++j < sl->map->y)
	{
		k = -1;
		while (++k < sl->map->x)
		{
			i = -1;
			while (++i < sl->map->z)
				render_tile(sl, k, j, i);
		}
	}
	sl_flush_window(&sl->window);
}
