/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:59:55 by jlenna            #+#    #+#             */
/*   Updated: 2022/10/06 17:13:04 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_hook(t_game *game)
{
	int	i;

	i = -1;
//	destroy_img(game);
	mlx_destroy_window(game->mlx, game->window);
//	free
	exit(0);
	return (0);
}
