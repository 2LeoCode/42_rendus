/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:34:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:18:15 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../mlx_rework/mlx_rework.h"
#include "../memory/memory.h"
#include "../string/string.h"

t_window	sl_new_window(int x, int y, char *title)
{
	t_window	win;

	win.data = ft_mlx_new_window(x, y, title);
	win.img = sl_new_image(x, y);
	return (win);
}

void	sl_image_to_window(t_window *win, const t_image *img, int x, int y)
{
	sl_image_copy(&win->img, img, x, y);
}

void	sl_flush_window(t_window *win)
{
	ft_mlx_put_image_to_window(win->data, win->img.data, 0, 0);
}
