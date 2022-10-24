/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:12:28 by jlenna            #+#    #+#             */
/*   Updated: 2022/10/06 17:12:29 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_xpm_format(char *texture_path)
{
	size_t	i;

	i = 0;
	while (texture_path[i])
		i++;
	while (texture_path[i] != '.' && i != 0)
		i--;
	if (!texture_path[i] || ft_strncmp(&texture_path[i], ".xpm\0", 5))
		return (0);
	return (1);
}

char	*get_texture_path(char *string, t_game *game)
{
	char	*path;
	int		i;
	int		fd;

	i = 0;
	while (string[i] != '.')
	{
		i++;
	}
	path = ft_strdup(&string[i]);
	fd = open(path, O_RDONLY);
	if (fd < 0 || !is_xpm_format(path))
	{
		free(path);
		exit_with_error("bad texture", game);
		return (NULL);
	}
	close(fd);
	return (path);
}

void	save_textures(t_game *game)
{
	int	i;
//	int	j;

	i = 0;
//	j = 0;
	while (i < game->file_lines_counter)
	{
//		if ((game->trimmed_file_lines[i][0] == 'N' \
//			&& game->trimmed_file_lines[i][1] == 'O' \
//			&& game->xpm_nswe[i] == NULL) \
//			|| (game->trimmed_file_lines[i][0] == 'S' \
//			&& game->trimmed_file_lines[i][1] == 'O' \
//			&& game->xpm_nswe[i] == NULL)
//			|| (game->trimmed_file_lines[i][0] == 'W' \
//			&& game->trimmed_file_lines[i][1] == 'E' \
//			&& game->xpm_nswe[i] == NULL)
//			|| (game->trimmed_file_lines[i][0] == 'E' \
//			&& game->trimmed_file_lines[i][1] == 'A' \
//			&& game->xpm_nswe[i] == NULL))
//		{
//			game->xpm_nswe[j++] = \
//			ft_strdup(get_texture_path(game->trimmed_file_lines[i], game));
//		}
		if ((game->trimmed_file_lines[i][0] == 'N' && game->trimmed_file_lines[i][1] == 'O' && game->xpm_nswe[3] == NULL))
		{
			game->xpm_nswe[3] = \
			ft_strdup(get_texture_path(game->trimmed_file_lines[i], game));
		}
		else if (game->trimmed_file_lines[i][0] == 'S' && game->trimmed_file_lines[i][1] == 'O' && game->xpm_nswe[1] == NULL)
		{
			game->xpm_nswe[1] = \
			ft_strdup(get_texture_path(game->trimmed_file_lines[i], game));
		}
		else if (game->trimmed_file_lines[i][0] == 'W' && game->trimmed_file_lines[i][1] == 'E' && game->xpm_nswe[0] == NULL)
		{
			game->xpm_nswe[0] = \
			ft_strdup(get_texture_path(game->trimmed_file_lines[i], game));
		}
		else if (game->trimmed_file_lines[i][0] == 'E' && game->trimmed_file_lines[i][1] == 'A' && game->xpm_nswe[2] == NULL)
		{
			game->xpm_nswe[2] = \
			ft_strdup(get_texture_path(game->trimmed_file_lines[i], game));
		}
		i++;
	}
}
