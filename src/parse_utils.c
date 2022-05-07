/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:46:50 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/06 18:46:52 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	checkarg(int argc)
{
	if (argc != 2)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		write(2, "Needs map file as input\n",
			ft_strlen("Needs map file as input\n"));
		exit(1);
	}
}

int	checkbody(char **map, int lines)
{
	int	x;
	int	y;
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

int	checkboundaries(char **map, int lines)
{
	int	limit;
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
				info.c = 1;
			if (map[y][x] == 'P')
				info.p += 1;
			if (map[y][x] == 'E')
				info.e = 1;
		}
		x = -1;
	}
	return (parsecriteria(info));
}

int	checkshape(char **map, int lines)
{
	int	i;
	int	y;

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
