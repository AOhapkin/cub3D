#include "cub3d.h"

static void	ray_init(t_game *game, t_ray *ray, float view)
{
	ray->dx = (float)cos(view);
	ray->dy = (float)-sin(view);
	ray->sx = round_float(ray->dx);
	ray->sy = round_float(ray->dy);
	ray->vert_x = (int) game->hero_x;
	if (ray->sx > 0)
		ray->vert_x += 1.0f;
	ray->hor_y = (int) game->hero_y;
	if (ray->sy > 0)
		ray->hor_y += 1.0f;
}

static void	ray_calc(t_game *game, t_ray *r)
{
	if (r->sx != 0)
	{
		r->vert_y = game->hero_y + r->dy / r->dx * (r->vert_x - game->hero_x);
		r->vert_dist = (float)sqrt(pow(game->hero_x - r->vert_x, 2.0)
							+ pow(game->hero_y - r->vert_y, 2.0));
		r->vert_w = r->vert_y - (int) r->vert_y;
		if (r->sx > 0)
			r->vert_w = 1 - r->vert_w;
	}
	else
		r->vert_dist = INFINITY;
	if (r->sy != 0)
	{
		r->hor_x = game->hero_x + r->dx / r->dy * (r->hor_y - game->hero_y);
		r->hor_dist = (float)sqrt(pow(game->hero_x - r->hor_x, 2.0)
						   + pow(game->hero_y - r->hor_y, 2.0));
		r->hor_w = r->hor_x - (int) r->hor_x;
		if (r->sy < 0)
			r->hor_w = 1 - r->hor_w;
	}
	else
		r->hor_dist = INFINITY;
}

static float	update_txt(t_game *game, float dis, int color_idx, float w)
{
	game->txt_idx = color_idx;
	game->txt_w = w;
	return (dis);
}

float	get_ray(t_game *game, float view_current) //вычисление дистанции
{
	t_ray	ray;

	ray_init(game, &ray, view_current);
	while (1)
	{
		ray_calc(game, &ray);
		if (ray.vert_dist < ray.hor_dist)
		{
			if (game->map[(int)ray.vert_y][(int)ray.vert_x + (ray.sx - 1) / 2] == '1')
				return (update_txt(game, ray.vert_dist, ray.sx + 1, ray.vert_w));
			else
				ray.vert_x += (float)ray.sx;
		}
		else
		{
			if (game->map[(int)ray.hor_y + (ray.sy - 1) / 2][(int)ray.hor_x] == '1')
				return (update_txt(game, ray.hor_dist, ray.sy + 2, ray.hor_w));
			else
				ray.hor_y += (float)ray.sy;
		}
	}
}

//int i - номер вертикальной линии на экране (от 0 до ширины окна)
//view_part - доля угла обзора (угол обзора деленный на ширину окна)
//view_current - текущая часть угла обзора (стар обзора - это направление взгляда минус половина угла обзора)

void	raycast(t_game *game)
{
	int		i;
	float	view_current;
	float	view_part;
	float	distance_to_wall;

	view_current = game->view - (FOV / 2);
	view_part = FOV / (WIN_WIDTH - 1);
	i = 0;
	while (i < WIN_WIDTH)
	{
		distance_to_wall = get_ray(game, view_current);
		draw_vertical_line(game, i, distance_to_wall); //умножить дистанцию (луч) на cos(game->view - view_current), чтобы убрать фишай
		view_current += view_part;
		i++;
	}
}