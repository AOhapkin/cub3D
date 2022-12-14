#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define GNL_BUFFER_SIZE 1
# define VALID_MAP_CHARS " 10NSWE"
# define VALID_EDGE_WALL_CHARS " 1"
# define INNER_MAP_CHARS "0NSEW"
# define EMPTY ' '
# define WALL '1'
# define FLOOR '0'
# define VALID_PLAYER_CHARS "NSWE"
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

# define WIN_WIDTH		640
# define WIN_NEIGHT		480
# define ANGLE_STEP		0.02f
# define LINEAR_STEP	0.3f
# define FOV			1.047f // угол обхора 60 градусов
# define MAP_SCALE		4

//keys

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_AR_UP		126
# define KEY_AR_LEFT	123
# define KEY_AR_DOWN	125
# define KEY_AR_RIGHT	124

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	NoEventMask = 0L,
	KeyPressMask = 1L<<0,
	KeyReleaseMask = 1L<<1,
	ButtonPressMask	= 1L<<2,
	ButtonReleaseMask = 1L<<3,
	EnterWindowMask	= 1L<<4,
	LeaveWindowMask = 1L<<5,
	PointerMotionMask = 1L<<6,
	PointerMotionHintMask = 1L<<7,
	Button1MotionMask = 1L<<8,
	Button2MotionMask = 1L<<9,
	Button3MotionMask = 1L<<10,
	Button4MotionMask = 1L<<11,
	Button5MotionMask = 1L<<12,
	ButtonMotionMask = 1L<<13,
	KeymapStateMask = 1L<<14,
	ExposureMask = 1L<<15,
	VisibilityChangeMask = 1L<<16,
	StructureNotifyMask = 1L<<17,
	ResizeRedirectMask = 1L<<18,
	SubstructureNotifyMask = 1L<<19,
	SubstructureRedirectMask = 1L<<20,
	FocusChangeMask = 1L<<21,
	PropertyChangeMask = 1L<<22,
	ColormapChangeMask = 1L<<23,
	OwnerGrabButtonMask = 1L<<24
};

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp; //bits_per_pixel
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_ray
{
	float	dx;
	float	dy;
	int		sx; //направление луча
	int		sy;
	float	hor_x;
	float	hor_y;
	float	vert_x;
	float	vert_y;
	float	vert_dist;
	float	hor_dist;
	float	vert_w;
	float	hor_w;
}	t_ray;

typedef struct s_game
{
	int		file_lines_counter;
	char	**file_lines;
	char	**trimmed_file_lines;
	//wall textures
	char	*xpm_nswe[4];
	//colors
	int		floor_color;
	int		ceiling_color;
	//map
	size_t	map_height;
	size_t	map_width;
	char	**map;
	//player
	float		hero_x;
	float		hero_y;
	float		view;
	float		txt_w;
	int			txt_idx;
	//mlx
	void	*mlx;
	void	*window;
	t_image	txt[4];
	t_image	img;
}			t_game;

char	*get_next_line(int fd);
void	exit_with_error(char *error_message, t_game *game);
void	parse_file(char *file, t_game *game);
void	trim_all_spaces(t_game *game);
void	check_number_of_params(t_game *game);
void	count_file_lines(t_game *game, char *file);
void	save_colors(t_game *game);
void	save_textures(t_game *game);
void	save_map(t_game *game);
void	validate_map(t_game *game);
void	set_map_with(t_game *game);
void	check_map_size(t_game *game);
void	validate_walls_by_lines(t_game *game);
void	validate_inner_map_chars(t_game *game);
void	init_new_game(t_game *game);
float	get_player_view(char player_start_char);

int		exit_hook(t_game *game);
void	raycast(t_game *game);
int		round_float(float f);
void	draw_vertical_line(t_game *game, int w, float dist);
void	recalculate_position(t_game *game, int move_direction);
float	get_ray(t_game *game, float view_current);

#endif