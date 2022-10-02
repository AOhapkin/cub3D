#include "cub3d.h"

int	is_xpm_format(char *texture_path)
{
	size_t	i;

	i = 0;
	while (texture_path[i])
		i++;
	while (texture_path[i] != '.' && i != 0)
		i--;
	if (!texture_path[i] || ft_strncmp(&texture_path[i], ".xpm\0", 5))
		return (0);
	return (1);
}

char	*get_texture_path(char *string, t_game *game)
{
	char	*path;
	int		i;
	int		fd;

	i = 0;
	while (string[i] != '.')
	{
		i++;
	}
	path = ft_strdup(&string[i]);
	fd = open(path, O_RDONLY);
	if (fd < 0 || !is_xpm_format(path))
	{
		free(path);
		exit_with_error("bad texture", game);
		return (NULL);
	}
	close(fd);
	return (path);
}

void	save_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->file_lines_counter)
	{
		if (game->trimmed_file_lines[i][0] == 'N' && game->trimmed_file_lines[i][1] == 'O' && game->no_path == NULL)
			game->no_path = ft_strdup(get_texture_path(game->trimmed_file_lines[i], game));
		else if (game->trimmed_file_lines[i][0] == 'S' && game->trimmed_file_lines[i][1] == 'O' && game->so_path == NULL)
			game->so_path = ft_strdup(get_texture_path(game->trimmed_file_lines[i], game));
		else if (game->trimmed_file_lines[i][0] == 'W' && game->trimmed_file_lines[i][1] == 'E' && game->we_path == NULL)
			game->we_path = ft_strdup(get_texture_path(game->trimmed_file_lines[i], game));
		else if (game->trimmed_file_lines[i][0] == 'E' && game->trimmed_file_lines[i][1] == 'A' && game->ea_path == NULL)
			game->ea_path = ft_strdup(get_texture_path(game->trimmed_file_lines[i], game));
		i++;
	}
	printf("%s\n", game->no_path);
}
