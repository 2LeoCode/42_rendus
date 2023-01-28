/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_xpm_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:32:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/07 23:59:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rework_int.h"

void	*ft_mlx_xpm_to_image(char **xpm, int *w, int *h)
{
	void	*ptr;

	ptr = mlx_xpm_to_image(*mlx_ptr(), xpm, w, h);
	save(ptr, ft_mlx_destroy_image);
	return (ptr);
}
