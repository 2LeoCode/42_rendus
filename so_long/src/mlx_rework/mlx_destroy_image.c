/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:49:30 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/08 00:00:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rework_int.h"

void	ft_mlx_destroy_image(void *img)
{
	mlx_destroy_image(*mlx_ptr(), img);
}
