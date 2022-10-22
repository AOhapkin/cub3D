/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:11:08 by jlenna            #+#    #+#             */
/*   Updated: 2022/10/22 13:10:11 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_file_name_ending(char *file_name, t_game *game)
{
	size_t	i;

	i = 0;
	while (file_name[i])
		i++;
	while (file_name[i] != '.' && i != 0)
		i--;
	if (!file_name[i] || ft_strncmp(&file_name[i], ".cub\0", 5))
		exit_with_error("wrong file type", game);
}

void	save_file_content(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;

	game->file_lines = malloc(sizeof(char *) * (game->file_lines_counter + 1));
	if (!game->file_lines)
		exit_with_error("malloc error", game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_error("can't open file", game);
	i = 0;
	while (i < game->file_lines_counter)
	{
		line = get_next_line(fd);
		game->file_lines[i] = ft_strdup(line);
		i++;
		free(line);
	}
}

void	get_player_start_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_strchr(VALID_PLAYER_CHARS, game->map[i][j]))
			{
				game->hero_x = (float)j + 0.5f;
				game->hero_y = (float)i + 0.5f;
				game->view = get_player_view(game->map[i][j]);
			}
			j++;
		}
		i++;
	}
	printf("hero_x: %f\n" \
			"hero_y: %f\n" \
			"view: %f\n", game->hero_x, game->hero_y, game->view);
}

void	save_map_params(t_game *game)
{
	trim_all_spaces(game);
	check_number_of_params(game);
	save_textures(game);
	save_colors(game);
}

void	parse_file(char *file, t_game *game)
{
	validate_file_name_ending(file, game);
	count_file_lines(game, file);
	save_file_content(game, file);
	save_map_params(game);
	save_map(game);
	get_player_start_position(game);
	validate_map(game);
}
