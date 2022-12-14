/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:09:49 by jlenna            #+#    #+#             */
/*   Updated: 2022/10/06 17:09:50 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	reset_game(t_game *game)
{
	int	i;

	if (!game)
		exit_with_error("malloc error", game);
	i = 0;
	while (i < 4)
		game->xpm_nswe[i++] = NULL;
	game->file_lines_counter = 0;
	game->file_lines = NULL;
	game->map_height = 0;
	game->map_width = 0;
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
	reset_game(game);
	parse_file(argv[1], game);
	init_new_game(game);
	exit_hook(game);
//	print_lines(game);
//	printf("file lines number: %d\n", game->file_lines_counter);
//	printf("map height: %d\n", game->map_height);
	return (0);
}
