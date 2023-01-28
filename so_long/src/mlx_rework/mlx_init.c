/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:46:01 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/05 22:26:08 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory/memory.h"
#include "mlx_rework_int.h"

void	ft_mlx_init(void)
{
	save(*mlx_ptr() = mlx_init(), ft_mlx_destroy_display);
}
