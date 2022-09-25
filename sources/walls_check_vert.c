#include "cub3d.h"

void	validate_inner_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_strchr(INNER_MAP_CHARS, game->map[i][j]))
				if ((game->map[i][j - 1] == EMPTY)
				|| (game->map[i][j + 1] == EMPTY)
					|| (game->map[i - 1][j] == EMPTY)
					|| (game->map[i + 1][j] == EMPTY)
					|| (game->map[i - 1][j + 1] == EMPTY)
					|| (game->map[i - 1][j - 1] == EMPTY)
					|| (game->map[i + 1][j + 1] == EMPTY)
					|| (game->map[i + 1][j - 1] == EMPTY))
					exit_with_error("fail wall check", game);
			j++;
		}
		i++;
	}
}
