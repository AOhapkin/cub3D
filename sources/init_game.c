/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:10:52 by jlenna            #+#    #+#             */
/*   Updated: 2022/10/06 17:10:53 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->wall[i].img_ptr = mlx_xpm_file_to_image(game->mlx, \
			game->xpm_nswe[i], &game->wall[i].width, \
			&game->wall[i].height);
		game->wall[i].addr = mlx_get_data_addr(game->wall[i].img_ptr, \
			&game->wall[i].bpp, \
			&game->wall[i].line_length, &game->wall[i].endian);
		i++;
	}
}

void	draw_background(t_game *game)
{
	int	i;
	int	*canvas;

	canvas = (int *)(game->background.addr);
	i = WIN_WIDTH * WIN_NEIGHT / 2;
	while (i > 0)
	{
		*canvas++ = game->ceiling_color;
		i--;
	}
	while (i > 0)
	{
		*canvas++ = game->floor_color;
		i--;
	}
}

void	draw_image(t_game *game)
{
	game->background.img_ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_NEIGHT);
	game->background.addr = \
	mlx_get_data_addr(game->background.img_ptr, &game->background.bpp, \
		&game->background.line_length, &game->background.endian);
	draw_background(game);
	//raycast()
	mlx_put_image_to_window(game->mlx, game->window, game->background.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->background.img_ptr);
}

// Нужно будет отсюда убрать это в другую функцию, это выход с кнопки
int	on_key_down(int keycode, t_game *game)
{
	draw_image(game);
	if (keycode == 53)
		exit_hook(game);
	return (0);
}

void	init_new_game(t_game *game)
{
	game->mlx = mlx_init();
	init_textures(game);
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_NEIGHT, "cub3D");
	draw_image(game);
	mlx_hook(game->window, ON_KEYDOWN, KeyPressMask, on_key_down, game);
	mlx_hook(game->window, ON_DESTROY, NoEventMask, exit_hook, game);
	mlx_loop(game->mlx);
}