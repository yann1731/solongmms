#include "../include/so_long.h"

int	checkbody(char **map, int lines)
{
	int	x;
	int y;
	int	limit;

	x = -1;
	y = -1;
	limit = 0;
	while (map[0][limit])
		limit++;
	while (++y < lines)
	{
		while (++x < (limit - 1))
		{
			if (validchar(map[y][x]) == 0)
				return (0);
		}
		x = -1;
	}
	return (1);
}