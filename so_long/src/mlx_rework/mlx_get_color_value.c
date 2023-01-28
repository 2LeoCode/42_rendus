/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_color_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:30:42 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/05 22:31:38 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rework_int.h"

unsigned int	ft_mlx_get_color_value(int color)
{
	return (mlx_get_color_value(*mlx_ptr(), color));
}
