#include "../include/so_long.h"

int	checkcoll(char **map)
{
	int y;
	int x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				i++;
			x++;
		}
		x = 0;
		y++;
	}
	return (i);
}