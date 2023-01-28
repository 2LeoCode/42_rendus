/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:26:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/06 17:47:07 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rework_int.h"

void	*ft_mlx_new_window(int x, int y, char *title)
{
	void	*ptr;

	save(ptr = mlx_new_window(*mlx_ptr(), x, y, title), ft_mlx_destroy_window);
	return (ptr);
}
