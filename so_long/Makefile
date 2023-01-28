SHELL	=	/bin/bash

NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -MMD -Iminilibx-linux #-g3 -fsanitize=address
LDFLAGS	=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -lbsd

MLX_DIR	=	minilibx-linux
MLX		=	$(MLX_DIR)/libmlx.a

SRC		=	src/main.c\
			src/dprintf/dflush.c\
			src/dprintf/dprintf_buffer.c\
			src/dprintf/dprintf.c\
			src/dprintf/print_arg.c\
			src/dprintf/print_char.c\
			src/dprintf/print_int.c\
			src/dprintf/print_str.c\
			src/game/image.c\
			src/game/init.c\
			src/game/mirror_image.c\
			src/game/render_flush.c\
			src/game/run.c\
			src/game/update_pos.c\
			src/game/window.c\
			src/memory/abort.c\
			src/memory/allocated_memory.c\
			src/memory/alloc.c\
			src/memory/clear_memory.c\
			src/memory/dealloc.c\
			src/memory/save.c\
			src/memory/swap.c\
			src/mlx_rework/mlx_clear_window.c\
			src/mlx_rework/mlx_destroy_display.c\
			src/mlx_rework/mlx_destroy_image.c\
			src/mlx_rework/mlx_destroy_window.c\
			src/mlx_rework/mlx_get_color_value.c\
			src/mlx_rework/mlx_init.c\
			src/mlx_rework/mlx_loop.c\
			src/mlx_rework/mlx_loop_end.c\
			src/mlx_rework/mlx_loop_hook.c\
			src/mlx_rework/mlx_new_image.c\
			src/mlx_rework/mlx_new_window.c\
			src/mlx_rework/mlx_ptr.c\
			src/mlx_rework/mlx_put_image_to_window.c\
			src/mlx_rework/mlx_xpm_file_to_image.c\
			src/mlx_rework/mlx_xpm_to_image.c\
			src/parsing/alloc_map.c\
			src/parsing/expect.c\
			src/parsing/parse.c\
			src/parsing/validate_map.c\
			src/stack/stack_empty.c\
			src/stack/stack_pop.c\
			src/stack/stack_push.c\
			src/stack/stack_size.c\
			src/string/isspace.c\
			src/string/memcmp.c\
			src/string/memcpy.c\
			src/string/memset.c\
			src/string/skip_nospace.c\
			src/string/skip_space.c\
			src/string/skip_space_til.c\
			src/string/strchr.c\
			src/string/string_alloc.c\
			src/string/string_append.c\
			src/string/string_realloc.c\
			src/string/strlen.c

OBJ		=	$(SRC:.c=.o)
DEP		=	$(OBJ:.o=.d)

all: $(MLX) $(NAME)

-include $(DEP)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(NAME)

re: fclean all
