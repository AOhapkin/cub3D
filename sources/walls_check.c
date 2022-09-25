#include "cub3d.h"

void	check_edge_line(char *map_line, t_game *game)
{
	int	i;

	i = 0;
	printf("%s\n", map_line);
	while (map_line[i])
	{
		if (!ft_strchr(VALID_EDGE_WALL_CHARS, map_line[i]))
			exit_with_error("invalid edge wall", game);
		i++;
	}
}

void	check_line(char *map_line, t_game *game)
{
	int	i;

	i = 0;
	while (map_line[i] == EMPTY)
		i++;
	if (map_line[i++] != WALL)
		exit_with_error("the map must be surrounded by walls", game);
	while (map_line[i])
	{
		if (map_line[i] == FLOOR && map_line[i + 1] == EMPTY)
			exit_with_error("empty space after floor", game);
		if (map_line[i] == EMPTY && map_line[i + 1] == FLOOR)
			exit_with_error("floor after empty space", game);
		i++;
	}
	i--;
	while (map_line[i] == EMPTY)
		i--;
	if (map_line[i] != WALL)
		exit_with_error("the map must be surrounded by walls", game);
}

void	validate_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->map_height)
	{
		if (i == 0 || i == (game->map_height))
			check_edge_line(game->map[i], game);
		else
			check_line(game->map[i], game);
		i++;
	}
}
