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
		game->txt[i].img_ptr = mlx_xpm_file_to_image(game->mlx, \
			game->xpm_nswe[i], &game->txt[i].width, \
			&game->txt[i].height);
		game->txt[i].addr = mlx_get_data_addr(game->txt[i].img_ptr, \
			&game->txt[i].bpp, \
			&game->txt[i].line_length, &game->txt[i].endian);
		i++;
	}
}

void	draw_background(t_game *game)
{
	int	i;
	int	*canvas;

	canvas = (int *)(game->img.addr);
	i = WIN_WIDTH * WIN_NEIGHT / 2;
	while (i > 0)
	{
		*canvas++ = game->ceiling_color;
		i--;
	}
	i = WIN_WIDTH * WIN_NEIGHT / 2;
	while (i > 0)
	{
		*canvas++ = game->floor_color;
		i--;
	}
}

void	draw_image(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_NEIGHT);
	game->img.addr = \
	mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, \
		&game->img.line_length, &game->img.endian);
	draw_background(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img_ptr);
}

// Нужно будет отсюда убрать это в другую функцию, это выход с кнопки
int	on_key_down(int keycode, t_game *game)
{
	draw_image(game);
	if (keycode == KEY_ESC)
		exit_hook(game);
	else if (keycode == KEY_W || keycode == KEY_AR_UP)
		recalculate_position(game, 0);
	else if (keycode == KEY_S || keycode == KEY_AR_DOWN)
		recalculate_position(game, 2);
	else if (keycode == KEY_A)
		recalculate_position(game, 3);
	else if (keycode == KEY_D)
		recalculate_position(game, 1);
	else if (keycode == KEY_AR_LEFT)
		game->view -= ANGLE_STEP * M_PI;
	else if (keycode == KEY_AR_RIGHT)
		game->view += ANGLE_STEP * M_PI;
	else
		return (0);
	raycast(game);
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
