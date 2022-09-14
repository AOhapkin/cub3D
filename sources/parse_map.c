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
	if (!game->file_lines)
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

void	trim_all_spaces(t_game *game)
{
	int	i;

	game->trimmed_file_lines = malloc(sizeof(char *) * (game->file_lines_counter + 1));
	if (!game->trimmed_file_lines)
		exit_with_error("malloc error", game);
	i = 0;
	while (i < game->file_lines_counter)
	{
		game->trimmed_file_lines[i] = ft_strtrim(game->file_lines[i], " ");
		i++;
	}
}

void	check_number_of_params(t_game *game)
{
	int	i;
	int	number_of_params;

	i = 0;
	number_of_params = 0;
	while (i < game->file_lines_counter)
	{
		if (game->trimmed_file_lines[i][0] == 'N' || game->trimmed_file_lines[i][0] == 'S'
		|| game->trimmed_file_lines[i][0] == 'W' || game->trimmed_file_lines[i][0] == 'E'
		|| game->trimmed_file_lines[i][0] == 'F' || game->trimmed_file_lines[i][0] == 'C')
			number_of_params++;
//		printf("char: %c\n", game->trimmed_file_lines[i][0]);
//		printf("counter: %d\n\n", number_of_params);
		i++;
	}
	if (number_of_params != 6)
		exit_with_error("Must be 6 (six) map params", game);
	printf("number_of_params: %d\n", number_of_params);
}

void save_map_params(t_game *game)
{
	trim_all_spaces(game);
	check_number_of_params(game);
}

void	parse_file(char *file, t_game *game)
{
	validate_file_name_ending(file, game);
	count_file_lines(game, file);
	printf("%d\n", game->file_lines_counter);
	save_file_content(game, file);
	save_map_params(game);
}
