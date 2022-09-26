#include "cub3d.h"

void	check_map_size(t_game *game)
{
	if (game->map_height < 3 || game->map_width < 3)
		exit_with_error("map is too small", game);
	printf("map size is ok\n");
}

void	set_map_with(t_game *game)
{
	size_t	width;
	int		i;

	i = 0;
	width = 0;
	while (game->map[i])
	{
		width = ft_strlen(game->map[i]);
		if (game->map_width < width)
			game->map_width = width;
		i++;
	}
}