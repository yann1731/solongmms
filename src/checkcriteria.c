#include "../include/so_long.h"

int	checkcriteria(char **map, int lines, t_criteria info)
{
	int			x;
	int			y;
	int			limit;

	x = -1;
	y = -1;
	limit = 0;
	while (map[0][limit])
		limit++;
	while (++y < (lines - 1))
	{
		while (++x < (limit - 1))
		{
			if (map[y][x] == 'C')
				info.C = 1;
			if (map[y][x] == 'P')
				info.P = 1;
			if (map[y][x] == 'E')
				info.E = 1;
		}
		x = -1;
	}
	return (parsecriteria(info));
}