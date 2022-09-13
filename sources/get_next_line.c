#include "cub3d.h"

char	*ft_read_to_n(int fd, char *str)
{
	char	*buf;
	int		i;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr_gnl(str, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		str = ft_strjoin_gnl(str, buf);
	}
	free(buf);
	return (str);
}

char	*ft_extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_remainder(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen_gnl(str) - i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*nextline;
	static char	*str;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	str = ft_read_to_n(fd, str);
	if (!str)
		return (NULL);
	nextline = ft_extract_line(str);
	str = ft_get_remainder(str);
	return (nextline);
}
