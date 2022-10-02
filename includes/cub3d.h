#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define GNL_BUFFER_SIZE 1
# define VALID_MAP_CHARS " 10NSWE"
# define VALID_EDGE_WALL_CHARS " 1"
# define INNER_MAP_CHARS "0NSEW"
# define EMPTY ' '
# define WALL '1'
# define FLOOR '0'
# define VALID_PLAYER_CHARS "NSWE"
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

# define WIN_NEIGHT		640
# define WIN_WIDTH		480

typedef struct s_game
{
	int		file_lines_counter;
	char	**file_lines;
	char	**trimmed_file_lines;
	//wall textures
//	char	*no_path;
//	char	*so_path;
//	char	*we_path;
//	char	*ea_path;
	char	*xpm_nswe[4];
	//colors
	int		floor_color;
	int		ceiling_color;
	//map
	size_t	map_height;
	size_t	map_width;
	char	**map;
	//player
	float		hero_x;
	float		hero_y;
	float		view;
	//mlx
	void	*mlx;
	void	*window;
}			t_game;

char	*get_next_line(int fd);
void	exit_with_error(char *error_message, t_game *game);
void	parse_file(char *file, t_game *game);
void	trim_all_spaces(t_game *game);
void	check_number_of_params(t_game *game);
void	count_file_lines(t_game *game, char *file);
void	save_colors(t_game *game);
void	save_textures(t_game *game);
void	save_map(t_game *game);
void	validate_map(t_game *game);
void	set_map_with(t_game *game);
void	check_map_size(t_game *game);
void	validate_walls_by_lines(t_game *game);
void	validate_inner_map_chars(t_game *game);
void	init_new_game(t_game *game);
float	get_player_view(char player_start_char);

#endif