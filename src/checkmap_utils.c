/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:18:47 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/06 18:18:52 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

char	**convertmaptostring(char *mapfile)
{
	int		fd;
	char	**map;
	char	*str;
	int		i;
	int		lines;

	i = 0;
	lines = countlines(mapfile);
	fd = open(mapfile, O_RDONLY);
	errorhandling(fd);
	map = malloc((lines + 1) * sizeof(char *));
	map[lines] = NULL;
	while (lines-- > 0)
	{
		str = get_next_line(fd);
		checkmalloc(str, map);
		map[i] = ft_strdup(str);
		free(str);
		i++;
	}
	lines = countlines(mapfile);
	map[lines - 1] = ft_strjoinfree(map[lines - 1], "\n");
	close(fd);
	return (map);
}

int	countlines(char *mapfile)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	fd = open(mapfile, O_RDONLY);
	errorhandling(fd);
	while (read(fd, &c, 1) != 0)
	{
		if (c == '\n')
			i++;
	}
	close(fd);
	return (i + 1);
}

void	initinfo(t_criteria *info)
{
	info->c = 0;
	info->e = 0;
	info->p = 0;
}

int	parsecriteria(t_criteria info)
{
	if (info.c == 1 && info.e == 1 && info.p == 1)
		return (1);
	return (0);
}

int	validchar(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}
