#include "cub3d.h"

int	rgb_atoi(const char *string, t_game *game)
{
	int		i;
	long	color_number;

	i = 0;
	color_number = 0;
	if (string[i] == ',')
		i++;
	if (string[i] < '0' || string[i] > '9')
		exit_with_error("RGB format error", game);
	while (string[i] >= '0' && string[i] <= '9')
	{
		color_number *= 10;
		color_number += ((int)string[i] - '0');
		i++;
	}
	while (string[i] && string[i] != ',')
	{
		if (string[i] != ' ')
			exit_with_error("RGB format error", game);
		i++;
	}
	if (color_number > 255)
		exit_with_error("RGB format error", game);
	return ((int)color_number);
}

void	check_rgb_chars(char *string, t_game *game)
{
	int	i;
	char c;

	i = 0;
	c = string[i];
	while (c != '\n' && c != '\0')
	{
		if (!ft_isdigit(c) && c != ',')
		{
			exit_with_error("RGB format error !!!!", game);
		}
		i++;
		c = string[i];
	}
}

int	get_color(char *string, t_game *game)
{
	int	r;
	int	g;
	int	b;

	while (!ft_isdigit(*string))
		string++;
	check_rgb_chars(string, game);
	r = rgb_atoi(string, game);
	string = ft_strchr(string, ',');
	g = rgb_atoi(string, game);
	string++;
	string = ft_strchr(string, ',');
	b = rgb_atoi(string, game);
	return (r << 16 | g << 8 | b);
}

void	save_colors(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->file_lines_counter)
	{
		if (game->trimmed_file_lines[i][0] == 'C')
		{
			game->ceiling_color = get_color(game->trimmed_file_lines[i], game);
		}
		if (game->trimmed_file_lines[i][0] == 'F')
		{
			game->floor_color = get_color(game->trimmed_file_lines[i], game);
		}
		i++;
	}
}
