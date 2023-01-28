/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:29:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:21:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../mlx_rework/mlx_rework.h"

#include <X11/X.h>
#include <stddef.h>

static int	sl_key_pressed(int key, t_gamedata *sl)
{
	static int	key_data[4] = {SL_KEY_W, SL_KEY_A, SL_KEY_S, SL_KEY_D};
	int			i;

	if (key == SL_KEY_ESC)
		ft_mlx_loop_end();
	else
	{
		i = -1;
		while (++i < 4)
		{
			if (key == key_data[i])
			{
				if (!sl->keys[i])
				{
					sl_update_pos(sl, i);
					sl->keys[i] = true;
					break ;
				}
			}
		}
	}
	return (0);
}

static int	sl_key_released(int key, t_gamedata *sl)
{
	static int	key_data[4] = {SL_KEY_W, SL_KEY_A, SL_KEY_S, SL_KEY_D};
	int			i;

	i = -1;
	while (++i < 4)
	{
		if (key == key_data[i])
			sl->keys[i] = false;
	}
	return (0);
}

void	sl_run(t_gamedata *sl)
{
	mlx_hook(sl->window.data, KeyPress, KeyPressMask, sl_key_pressed, sl);
	mlx_hook(sl->window.data, KeyRelease, KeyReleaseMask, sl_key_released, sl);
	mlx_hook(sl->window.data, DestroyNotify, StructureNotifyMask,
		(void *)ft_mlx_loop_end, NULL);
	ft_mlx_loop_hook((void *)sl_render_flush, sl);
	ft_mlx_loop();
}
