/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:35:30 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/12 15:47:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rework_int.h"

void	ft_mlx_loop_hook(int (*fptr)(), void *param)
{
	mlx_loop_hook(*mlx_ptr(), fptr, param);
}
