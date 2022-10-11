#include "cub3d.h"

int	round_float(float f)
{
	if (f < 0.0f)
	{
		if (f > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (f < 0.000001f)
			return (0);
		else
			return (1);
	}
}

void	recalculate_position(t_game *game, int move_direction)
{
	float	dist;
	float	dx;
	float	dy;
	float	angle;

	angle = game->view + move_direction * M_PI / 2;
	dx = LINEAR_STEP * cos(angle);
	dy = LINEAR_STEP * sin(angle);
	dist = get_ray(game, round_float(dy) * M_PI / 2);
	if (dist * dist < dy * dy)
		dy = 0.0f; //зануляем шаг до y, если дошли до стены
	dist = get_ray(game, (1 - (round_float(dx) + 1) / 2) * M_PI);
	if (dist * dist < dx * dx)
		dx = 0.0f; //зануляем шаг до x, если дошли до стены
	dist = get_ray(game, angle);
	if (dist * dist < dy * dy + dx * dx)
		if (round_float(dy) * round_float(dx) != 0)
			dy = 0.0f;
	game->hero_x += dx;
	game->hero_y -= dy;
}