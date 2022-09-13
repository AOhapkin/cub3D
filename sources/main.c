#include "cub3d.h"

void	exit_with_error(char *error_message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error_message, 2);
//	free_game(game);
	ft_putstr_fd("\nExit\n", 2);
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game)
{
	if (!game)
		exit_with_error("malloc error");
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
	game->error_exit = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_with_error("program works with one argument only");
	game = malloc(sizeof(t_game));
	init_game(game);
	parse_file(argv[1], game);
	return (0);
}