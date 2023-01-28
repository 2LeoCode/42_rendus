/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:03:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 17:04:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../memory/memory.h"

t_image	sl_mirror_image(const t_image *src)
{
	t_image	img;
	int		i;
	int		j;

	img = sl_image_from(src);
	i = -1;
	while (++i < img.h)
	{
		j = -1;
		while (++j < img.w / 2 + !!(img.w % 2))
		{
			ft_swap(img.pixels + i * img.size_line + j,
				img.pixels + i * img.size_line + img.w - j - 1,
				sizeof(*img.pixels));
		}
	}
	return (img);
}
