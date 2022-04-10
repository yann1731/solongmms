#include "../include/so_long.h"

int	checkmap(char **map)
{
	int	lines;
	int	x;
	int y;
	t_criteria info;

	lines = 0;
	while (map[lines])
		lines++;
	x = -1;
	y = 0;
	if (checkboundaries(map, lines) == 0)
		return (0);
	if (checkbody(map, lines) == 0)
		return (0);
	if (checkcriteria(map, lines, info) == 0)
		return (0);
	
	return (1);
}