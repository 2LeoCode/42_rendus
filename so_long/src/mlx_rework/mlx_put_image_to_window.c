/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_image_to_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:28:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/05 22:30:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rework_int.h"

void	ft_mlx_put_image_to_window(void *win, void *img, int x, int y)
{
	mlx_put_image_to_window(*mlx_ptr(), win, img, x, y);
}
