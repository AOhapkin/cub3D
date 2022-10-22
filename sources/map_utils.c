/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:10:57 by jlenna            #+#    #+#             */
/*   Updated: 2022/10/22 13:06:24 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_size(t_game *game)
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
				if ((game->map[i][j - 1] == WALL)
				&& (game->map[i][j + 1] == WALL)
					&& (game->map[i - 1][j] == WALL)
					&& (game->map[i + 1][j] == WALL)
					&& (game->map[i - 1][j + 1] == WALL)
					&& (game->map[i - 1][j - 1] == WALL)
					&& (game->map[i + 1][j + 1] == WALL)
					&& (game->map[i + 1][j - 1] == WALL))
					exit_with_error("map is too small", game);
			j++;
		}
		i++;
	}
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
