#include "cub3d.h"

void	exit_with_error(char *error_message)
{
	printf("Exit with error: %s\n", error_message);
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game)
{
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_with_error("program works with one argument only");
	init_game(&game);
	parse_map(argv[1], &game);
	return (0);
}