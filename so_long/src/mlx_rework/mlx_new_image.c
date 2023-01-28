/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:27:33 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/08 00:00:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rework_int.h"

void	*ft_mlx_new_image(int w, int h)
{
	void	*ptr;

	save(ptr = mlx_new_image(*mlx_ptr(), w, h), ft_mlx_destroy_image);
	return (ptr);
}
