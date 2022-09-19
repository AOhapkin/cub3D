#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define GNL_BUFFER_SIZE 1

typedef struct s_game
{
	int		file_lines_counter;
	char	**file_lines;
	char	**trimmed_file_lines;
	//wall textures
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	//colors
	int		floor_color;
	int		ceiling_color;
}			t_game;

char	*get_next_line(int fd);
void	exit_with_error(char *error_message, t_game *game);
void	parse_file(char *file, t_game *game);
void	trim_all_spaces(t_game *game);
void	check_number_of_params(t_game *game);
void	count_file_lines(t_game *game, char *file);
void	save_colors(t_game *game);
void	save_textures(t_game *game);


#endif