/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rework.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:30:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:50:37 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_REWORK_H
# define MLX_REWORK_H

void			ft_mlx_init(void);
void			ft_mlx_destroy_display(void *mlx_key);
void			ft_mlx_clear_window(void *win);
void			ft_mlx_destroy_window(void *win);
void			ft_mlx_destroy_image(void *img);

void			*ft_mlx_new_window(int x, int y, char *title);
void			*ft_mlx_new_image(int w, int h);
void			ft_mlx_put_image_to_window(void *win, void *img, int x, int y);

unsigned int	ft_mlx_get_color_value(int color);

void			*ft_mlx_xpm_to_image(char **xpm, int *w, int *h);
void			*ft_mlx_xpm_file_to_image(char *path, int *w, int *h);

void			ft_mlx_loop(void);
void			ft_mlx_loop_end(void);
void			ft_mlx_loop_hook(int (*fptr)(), void *param);

#endif
