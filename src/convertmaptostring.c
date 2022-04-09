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
	close(fd);
	return (map);
}