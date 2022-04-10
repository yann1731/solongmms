#include "../include/so_long.h"

char	**convertmaptostring(char *mapfile)
{
	int		fd;
	char	**map;
	char	*str;
	int		i;
	int		lines;

	i = 0;
	lines = countlines(mapfile);
	fd = open(mapfile, O_RDONLY);
	map = malloc((lines + 1) * sizeof(char *));
	map[lines] = NULL;
	while (lines-- > 0)
	{
		str = get_next_line(fd);
		map[i] = ft_strdup(str);
		free(str);
		i++;
	}
	lines = countlines(mapfile);
	map[lines - 1] = ft_strjoinfree(map[lines - 1], "\n");
	close(fd);
	return (map);
}

int	countlines(char *mapfile)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	fd = open(mapfile, O_RDONLY);
	while (read(fd, &c, 1) != 0)
	{
		if (c == '\n')
			i++;
	}
	close(fd);
	return (i + 1);
}

void	initinfo(t_criteria *info)
{
	info->C = 0;
	info->E = 0;
	info->P = 0;
}

int	parsecriteria(t_criteria info)
{
	if (info.C == 1 && info.E == 1 && info.P == 1)
		return (1);
	return (0);
}

int	validchar(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}
