#include "cub3d.h"

void	validate_file_name_ending(char *file_name, t_game *game)
{
	size_t	i;

	i = 0;
	while (file_name[i])
		i++;
	while (file_name[i] != '.' && i != 0)
		i--;
	printf("%s\n", &file_name[i]);
	if (!file_name[i] || ft_strncmp(&file_name[i], ".cub\0", 5))
		exit_with_error("wrong file type", game);
//	else
//		printf("file type is ok\n");
}

void	count_file_lines(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		lines_counter;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_error("can't open file", game);
	line = get_next_line(fd);
	lines_counter = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		lines_counter++;
	}
	free(line);
	close(fd);
	game->file_lines_counter = lines_counter;
}

void	save_file_content(t_game *game, char *file)
{
	int 	fd;
	int		i;
	char	*line;

	game->file_lines = malloc(sizeof(char *) * (game->file_lines_counter + 1));
	game->trimmed_file_lines = malloc(sizeof(char *) * (game->file_lines_counter + 1));
	if (!game->file_lines || !game->trimmed_file_lines)
		exit_with_error("malloc error", game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_error("can't open file", game);
	i = 0;
	while (i < game->file_lines_counter)
	{
		line = get_next_line(fd);
		game->file_lines[i] = ft_strdup(line);
//		printf("%s\n", game->file_lines[i]);
		i++;
		free(line);
	}
}

void	parse_file(char *file, t_game *game)
{
	validate_file_name_ending(file, game);
	count_file_lines(game, file);
	printf("%d\n", game->file_lines_counter);
	save_file_content(game, file);
}
