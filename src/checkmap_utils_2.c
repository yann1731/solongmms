/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:19:08 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/06 18:19:11 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	checkmap(char **map)
{
	int			lines;
	int			x;
	int			y;
	t_criteria	info;

	lines = 0;
	initinfo(&info);
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

void	replace_p(t_player *player)
{
	int	y;
	int	x;

	y = player->y_pos;
	x = player->x_pos;
	player->map[y][x] = '0';
}

int	checkmapformat(char *argv)
{
	if (ft_strnstrint(argv, ".ber", ft_strlen(argv)) == 1)
		return (1);
	return (0);
}

void	memfree(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	checkmalloc(char *str, char **map)
{
	int	i;

	i = -1;
	if (!str)
	{
		memfree(map);
		exit(1);
	}
	if (!map && str)
	{
		free(str);
		exit(1);
	}
}
