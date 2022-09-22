#include "cub3d.h"

void	save_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->trimmed_file_lines[i][0] != '1')
		i++;
	game->map_height = game->file_lines_counter - i - 1;
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		exit_with_error("malloc error", game);
	j = 0;
	while (i < game->file_lines_counter)
	{
		game->map[j] = game->file_lines[i];
		printf("map[%d]_%s\n", j, game->map[j]);
		i++;
		j++;
	}
}
