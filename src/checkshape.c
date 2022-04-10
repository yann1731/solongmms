#include "../include/so_long.h"

int	checkshape(char **map, int lines)
{
	int i;
	int y;

	i = 0;
	y = 0;
	i = ft_strlen(map[y]);
	while (map[++y])
	{
		if (ft_strlen(map[y]) != i)
			return (0);
	}
	return (1);
}