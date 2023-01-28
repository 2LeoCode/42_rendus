/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_xpm_file_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:33:41 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:50:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rework_int.h"

void	*ft_mlx_xpm_file_to_image(char *path, int *w, int *h)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(*mlx_ptr(), path, w, h);
	save(ptr, ft_mlx_destroy_image);
	return (ptr);
}
