/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check_vert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:12:34 by jlenna            #+#    #+#             */
/*   Updated: 2022/10/06 17:12:35 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_inner_map_chars(t_game *game)
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
				if ((game->map[i][j - 1] == EMPTY)
				|| (game->map[i][j + 1] == EMPTY)
					|| (game->map[i - 1][j] == EMPTY)
					|| (game->map[i + 1][j] == EMPTY)
					|| (game->map[i - 1][j + 1] == EMPTY)
					|| (game->map[i - 1][j - 1] == EMPTY)
					|| (game->map[i + 1][j + 1] == EMPTY)
					|| (game->map[i + 1][j - 1] == EMPTY))
					exit_with_error("fail wall check", game);
			j++;
		}
		i++;
	}
}
