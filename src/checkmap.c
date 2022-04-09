#include "../include/so_long.h"

int	checkmap(char **map)
{
	int	lines;
	int	i;

	lines = 0;
	i = 0;
	while (map[lines])
		lines++;
	printf("%d", lines);
	return (0);
}