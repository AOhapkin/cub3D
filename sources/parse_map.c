#include "cub3d.h"

void	validate_file_name_ending(char *file_name)
{
	size_t	i;

	i = 0;
	while (file_name[i])
		i++;
	while (file_name[i] != '.' && i != 0)
		i--;
	printf("%s\n", &file_name[i]);
	if (!file_name[i] || ft_strncmp(&file_name[i], ".cub\0", 5))
		exit_with_error("wrong file type");
//	else
//		printf("file type is ok\n");
}

void	parse_file(char *file_name, t_game *game)
{
	int		fd;
	char	*line;
	int		info_counter;

	validate_file_name_ending(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_with_error("can't open file");
//	line = get_next_line(fd);
//	info_counter = 0;
//	while (line)
//	{
//		if (save_map_info(line, game, &info_counter))
//			i++;
//		line = get_next_line(fd);
//	}
	close(fd);
}
