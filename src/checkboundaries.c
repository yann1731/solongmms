#include "../include/so_long.h"

int	checkboundaries(char **map, int lines)
{
	int limit;
	int	i;
	int	y;

	limit = 0;
	i = -1;
	y = -1;
	while (map[0][limit])
		limit++;
	while (++i < (limit - 1))
		if (map[0][i] != '1' || map[lines - 1][i] != '1')
			return (0);
	while (++y < lines)
		if (map[y][0] != '1' || map[y][limit - 2] != '1')
			return (0);
	return (1);
}