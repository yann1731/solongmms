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
	if (checkshape(map, lines) == 0)
		return (0);
	return (1);
}

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

int	checkcriteria(char **map, int lines, t_criteria info)
{
	int			x;
	int			y;
	int			limit;

	x = -1;
	y = -1;
	limit = 0;
	initinfo(&info);
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
