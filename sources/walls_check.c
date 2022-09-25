#include "cub3d.h"

void	check_edge_wall(char *map_line, t_game *game)
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

void	validate_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->map_height)
	{
		if (i == 0 || i == (game->map_height))
			check_edge_wall(game->map[i], game);
		i++;
	}
}