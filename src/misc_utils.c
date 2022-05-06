/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:30:26 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/06 18:30:29 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	checkcoll(char **map)
{
	int	y;
	int	x;
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

void	get_map_size(char **map, int *y_map, int *x_map)
{
	*y_map = 0;
	*x_map = 0;
	while (map[*y_map])
		*y_map += 1;
	while (map[0][*x_map] != '\n')
		*x_map += 1;
}

void	get_player_pos(char **map, int *y_pos, int *x_pos)
{
	*x_pos = 0;
	*y_pos = 0;
	while (map[*y_pos])
	{
		while (map[*y_pos][*x_pos])
		{
			if (map[*y_pos][*x_pos] == 'P')
				return ;
			*x_pos += 1;
		}
	*y_pos += 1;
	*x_pos = 0;
	}
}
