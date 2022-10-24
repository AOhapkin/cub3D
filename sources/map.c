/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:11:01 by jlenna            #+#    #+#             */
/*   Updated: 2022/10/06 17:11:02 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		i++;
		j++;
	}
	set_map_with(game);
}

void	check_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!ft_strchr(VALID_MAP_CHARS, game->map[i][j]))
				exit_with_error("invalid map symbol", game);
			j++;
		}
		i++;
	}
}

void	check_number_of_players(t_game *game)
{
	int	i;
	int	j;
	int	number_of_players;

	i = 0;
	number_of_players = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_strchr(VALID_PLAYER_CHARS, game->map[i][j]))
				number_of_players++;
			j++;
		}
		i++;
	}
	if (number_of_players != 1)
		exit_with_error("invalid number of players", game);
}

void	validate_map(t_game *game)
{
	check_map_chars(game);
	check_number_of_players(game);
	validate_walls_by_lines(game);
	validate_inner_map_chars(game);
}
