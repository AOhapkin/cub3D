#include "cub3d.h"

void	exit_with_error(char *error_message, t_game *game)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error_message, 2);
//	free_game(game);
	(void) game;
	ft_putstr_fd("\nExit\n", 2);
	exit(1);
}

void	init_game(t_game *game)
{
	if (!game)
		exit_with_error("malloc error", game);
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
	game->file_lines_counter = 0;
	game->file_lines = NULL;
}

void	print_lines(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->file_lines_counter)
	{
		printf("%s\n", game->trimmed_file_lines[i++]);
	}
//	printf("%s\n", game->file_lines[0]);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc != 2)
		exit_with_error("program works with one argument only", game);
	init_game(game);
	parse_file(argv[1], game);
//	print_lines(game);
	return (0);
}