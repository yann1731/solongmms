#include "../include/so_long.h"

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