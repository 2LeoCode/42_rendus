/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:44:53 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/05 22:47:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rework_int.h"
#include <stdlib.h>

void	ft_mlx_destroy_display(void *mlx_key)
{
	mlx_destroy_display(mlx_key);
	free(mlx_key);
}
