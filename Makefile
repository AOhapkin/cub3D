NAME = cub3D

INCLUDES = includes
HEADER = $(INCLUDES)/cub3d.h

DIR_S		= sources/
DIR_O		= objects/
C_FILES		= main.c parse_file.c parse_utils.c get_next_line.c \
			textures.c colors.c map.c map_utils.c walls_check_hor.c walls_check_vert.c \
			init_game.c exit.c raycast.c ray_utils.c draw_lines.c
SRCS = $(addprefix $(DIR_S),$(C_FILES))
OBJS = $(addprefix $(DIR_O),$(C_FILES:.c=.o))

#libft
LIBFT_DIR = libft
LIBFT_INCLUDES = $(LIBFT_DIR)/includes
LIBFT_HEADER = $(LIBFT_INCLUDES)/libft.h
LIBFT = $(LIBFT_DIR)/libft.a

#MLX
MLX_DIR	= mlx
MLX	= $(MLX_DIR)/libmlx.a

#flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L minilibx_opengl_20191021 -framework OpenGL -framework AppKit

.PHONY: all libft clean fclean re

all: mlx libft $(DIR_O) $(NAME)

libft:
	make -C $(LIBFT_DIR)

mlx:
	make -C $(MLX_DIR)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $@

$(DIR_O)%.o: $(DIR_S)%.c $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -I $(MLX_DIR) -c $< -o $@

$(DIR_O):
	mkdir -p $(DIR_O)

clean:
	rm -rf $(DIR_O)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean:	clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re:	fclean all