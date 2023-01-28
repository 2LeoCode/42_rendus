/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:38:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:17:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <stdbool.h>

# define SL_BUFFER_SIZE 2048

# define WINDOW_X 1280
# define WINDOW_Y 720

# define TILE_SIZE 72
# define ITEM_SIZE 36
# define PLAYER_X 40
# define PLAYER_Y 92

# define ITEM_OFFSET 18
# define PLAYER_X_OFFSET 13
# define PLAYER_Y_OFFSET 67

# define X_OFFSET 32
# define Y_OFFSET 16
# define Z_OFFSET 38

# define SL_KEY_W 119
# define SL_KEY_A 97
# define SL_KEY_S 115
# define SL_KEY_D 100
# define SL_KEY_ESC 65307

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}	t_vec3;

typedef struct s_rect
{
	int	w;
	int	h;
}	t_rect;

typedef struct s_trgb
{
	unsigned char	b:8;
	unsigned char	g:8;
	unsigned char	r:8;
	unsigned char	t:8;
}	t_trgb;

typedef struct s_image
{
	int			w;
	int			h;
	int			bpp;
	int			size_line;
	int			endian;
	void		*data;
	t_trgb		*pixels;
}	t_image;

typedef struct s_window
{
	void		*data;
	t_image		img;
}	t_window;

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	t_vec3	player_spawn;
	int		item_cnt;
	int		exit_cnt;
	char	**data[];
}	t_map;

enum e_textindex
{
	GRASS_BLOCK,
	STONE_BRICKS,
	CHISELED_STONE_BRICKS,
	BLOCK_OF_DIAMOND,
	LAVA,
	EMERALD,
	STEVE,
	STEVE_2,
	STEVE_BACK,
	STEVE_BACK_2,
	STEVE_LYING,
	STEVE_LYING_2,
	STEVE_SNEAKING,
	STEVE_SNEAKING_2
};

enum e_sl_direction
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

typedef struct s_gamedata
{
	t_window	window;
	t_vec3		player;
	t_image		*textures;
	t_map		*map;
	t_image		*map_img;
	bool		keys[4];
	t_vec2		mouse[2];
	t_vec2		origin;
	int			player_texture;
}	t_gamedata;

void		sl_init(t_gamedata *sl, const char *map_path);
void		sl_run(t_gamedata *sl);

t_window	sl_new_window(int x, int y, char *title);
void		sl_image_to_window(t_window *win, const t_image *img, int x, int y);
void		sl_flush_window(t_window *win);

t_image		sl_new_image(int w, int h);
t_image		sl_xpm_file_to_image(char *path, int w, int h);
t_image		sl_mirror_image(const t_image *src);
t_image		*sl_image_copy(t_image *dst, const t_image *src, int x, int y);
t_image		sl_image_from(const t_image *src);

t_vec2		sl_get_origin(t_vec3 player);
void		sl_update_pos(t_gamedata *sl, int pos);

void		sl_render_flush(t_gamedata *sl);

#endif
