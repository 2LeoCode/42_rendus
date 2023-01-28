/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:09:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 17:04:54 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../mlx_rework/mlx_rework.h"
#include "../memory/memory.h"
#include "../string/string.h"

t_image	sl_new_image(int w, int h)
{
	t_image	img;

	img.w = w;
	img.h = h;
	img.data = ft_mlx_new_image(w, h);
	img.pixels = (t_trgb *)mlx_get_data_addr(
			img.data, &img.bpp, &img.size_line, &img.endian);
	img.size_line /= sizeof(*img.pixels);
	return (img);
}

t_image	sl_xpm_file_to_image(char *path, int w, int h)
{
	t_image	img;
	t_image	tmp;
	int		i;
	int		j;

	tmp.data = ft_mlx_xpm_file_to_image(path, &tmp.w, &tmp.h);
	tmp.pixels = (t_trgb *)mlx_get_data_addr(
			tmp.data, &tmp.bpp, &tmp.size_line, &tmp.endian);
	tmp.size_line /= sizeof(*tmp.pixels);
	img = sl_new_image(w, h);
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
			img.pixels[i * img.size_line + j]
				= tmp.pixels[(i * tmp.h / h) * tmp.size_line + (j * tmp.w / w)];
	}
	dealloc(tmp.data);
	return (img);
}

t_image	sl_image_from(const t_image *src)
{
	t_image	img;

	img = sl_new_image(src->w, src->h);
	ft_memcpy(img.pixels, src->pixels,
		sizeof(*img.pixels) * img.size_line * img.h);
	return (img);
}

void	adjust_endpos(t_vec2 *end, t_vec2 pos,
	const t_image *dst, const t_image *src)
{
	end->x = pos.x + src->w;
	if (end->x > dst->w)
		end->x = dst->w;
	end->y = pos.y + src->h;
	if (end->y > dst->h)
		end->y = dst->h;
}

t_image	*sl_image_copy(t_image *dst, const t_image *src, int x, int y)
{
	const t_vec2	begin = {x, y};
	t_vec2			end;
	int				i;

	adjust_endpos(&end, (t_vec2){x, y}, dst, src);
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	while (y < end.y)
	{
		while (x < end.x)
		{
			i = (y - begin.y) * src->size_line + (x - begin.x);
			if ((*(int *)(src->pixels + i) & 0xc90280) != 0xc90280)
				dst->pixels[y * dst->size_line + x] = src->pixels[i];
			++x;
		}
		x = begin.x;
		if (x < 0)
			x = 0;
		++y;
	}
	return (dst);
}
