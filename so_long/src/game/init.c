/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:31:59 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 17:01:07 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../mlx_rework/mlx_rework.h"
#include "../memory/memory.h"
#include "../dprintf/dprintf.h"
#include "../string/string.h"
#include "../parsing/parsing.h"

static void	load_textures(t_image *textures)
{
	textures[GRASS_BLOCK] = sl_xpm_file_to_image(
			"assets/blocks/grass_block.xpm", TILE_SIZE, TILE_SIZE);
	textures[STONE_BRICKS] = sl_xpm_file_to_image(
			"assets/blocks/stone_bricks.xpm", TILE_SIZE, TILE_SIZE);
	textures[CHISELED_STONE_BRICKS] = sl_xpm_file_to_image(
			"assets/blocks/chiseled_stone_bricks.xpm", TILE_SIZE, TILE_SIZE);
	textures[BLOCK_OF_DIAMOND] = sl_xpm_file_to_image(
			"assets/blocks/block_of_diamond.xpm", TILE_SIZE, TILE_SIZE);
	textures[LAVA] = sl_xpm_file_to_image(
			"assets/blocks/lava.xpm", TILE_SIZE, TILE_SIZE);
	textures[EMERALD] = sl_xpm_file_to_image(
			"assets/items/emerald.xpm", ITEM_SIZE, ITEM_SIZE);
	textures[STEVE] = sl_xpm_file_to_image(
			"assets/player/steve.xpm", PLAYER_X, PLAYER_Y);
	textures[STEVE_BACK] = sl_xpm_file_to_image(
			"assets/player/steve_back.xpm", PLAYER_X, PLAYER_Y);
	textures[STEVE_LYING] = sl_xpm_file_to_image(
			"assets/player/steve_lying.xpm", PLAYER_Y, PLAYER_X);
	textures[STEVE_SNEAKING] = sl_xpm_file_to_image(
			"assets/player/steve_sneaking.xpm", PLAYER_X, PLAYER_Y);
	textures[STEVE_2] = sl_mirror_image(textures + STEVE);
	textures[STEVE_BACK_2] = sl_mirror_image(textures + STEVE_BACK);
	textures[STEVE_LYING_2] = sl_mirror_image(textures + STEVE_LYING);
	textures[STEVE_SNEAKING_2] = sl_mirror_image(textures + STEVE_SNEAKING);
}

void	sl_init(t_gamedata *sl, const char *map_path)
{
	ft_memset(sl, 0, sizeof(*sl));
	sl->map = sl_parse(map_path);
	sl->player = sl->map->player_spawn;
	sl->origin = sl_get_origin(sl->player);
	ft_mlx_init();
	sl->window = sl_new_window(1280, 720, "so_long");
	sl->textures = alloc(14 * sizeof(t_image));
	load_textures(sl->textures);
	sl->player_texture = STEVE;
}
