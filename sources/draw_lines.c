#include "cub3d.h"

void	draw_vertical_line(t_game *game, int w, float dist)
{
	unsigned int	*dst;
	unsigned int	*src;
	unsigned int	h;
	float			src_f;
	float			d_shift;

	h = (float) WIN_NEIGHT / dist; // высота линии h обратно пропорц дистанции dist
	src_f = 0.0f;
	d_shift = (float) game->txt[game->txt_idx].height / h;
	if (h > WIN_NEIGHT)
	{
		src_f = 0.5f * (h - WIN_NEIGHT) / h * game->txt[game->txt_idx].height;
		h = WIN_NEIGHT;
	}
	src = (unsigned int *) game->txt[game->txt_idx].addr;
	src += (int)((float) game->txt_w * game->txt[game->txt_idx].width);
	dst = (unsigned int *) game->img.addr + w + (WIN_NEIGHT - h) / 2 * WIN_WIDTH;
	while (h-- > 0)
	{
		*dst = *(src + ((int)src_f) * game->txt[game->txt_idx].width);
		dst += WIN_WIDTH;
		src_f += d_shift;
	}
}