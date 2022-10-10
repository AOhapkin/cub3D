/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:11:44 by jlenna            #+#    #+#             */
/*   Updated: 2022/10/06 17:12:13 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	trim_all_spaces(t_game *game)
{
	int	i;

	game->trimmed_file_lines = malloc(sizeof(char *) \
								* (game->file_lines_counter + 1));
	if (!game->trimmed_file_lines)
		exit_with_error("malloc error", game);
	i = 0;
	while (i < game->file_lines_counter)
	{
		game->trimmed_file_lines[i] = ft_strtrim(game->file_lines[i], " ");
		i++;
	}
}

void	check_number_of_params(t_game *game)
{
	int	i;
	int	number_of_params;

	i = 0;
	number_of_params = 0;
	while (i < game->file_lines_counter)
	{
		if (game->trimmed_file_lines[i][0] == 'N' \
			|| game->trimmed_file_lines[i][0] == 'S'
			|| game->trimmed_file_lines[i][0] == 'W' \
			|| game->trimmed_file_lines[i][0] == 'E' \
			|| game->trimmed_file_lines[i][0] == 'F' \
			|| game->trimmed_file_lines[i][0] == 'C')
			number_of_params++;
		i++;
	}
	if (number_of_params != 6)
		exit_with_error("Must be 6 (six) map params", game);
}

void	count_file_lines(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		lines_counter;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_error("can't open file", game);
	line = get_next_line(fd);
	lines_counter = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		lines_counter++;
	}
	free(line);
	close(fd);
	game->file_lines_counter = lines_counter;
}

float	get_player_view(char player_start_char)
{
	if (player_start_char == NORTH)
		return ((float)(0.5f * M_PI));
	else if (player_start_char == SOUTH)
		return ((float)(-0.5f * M_PI));
	else if (player_start_char == WEST)
		return ((float)(1.0f * M_PI));
	else
		return ((float)(0.0f * M_PI));
}
