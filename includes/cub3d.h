#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define BUFFER_SIZE 1

typedef struct s_game
{
	//wall textures
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	//colors
}			t_game;

// gnl + gnl_utils
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *str, int c);
char	*ft_init(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

void	exit_with_error(char *error_message);
void	parse_map(char *file_name, t_game *game);


#endif