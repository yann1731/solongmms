/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:25:57 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/06 18:26:00 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	closeondestroy(t_player *player)
{
	memfree(player->map);
	mlx_destroy_window(player->vars.mlx, player->vars.win);
	exit(0);
}

void	closeprogram(t_player *player)
{
	memfree(player->map);
	mlx_destroy_window(player->vars.mlx, player->vars.win);
	exit(0);
}

void	errorhandling(int status)
{
	if (status == 0)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		write(2, "Incorrect map parameters\n",
			ft_strlen("Incorrect map parameters\n"));
		exit(1);
	}
	if (status == -1)
	{
		perror("Error");
		exit(1);
	}
}

void	errorhandlingmap(int status, char **map)
{
	if (status == 0)
	{
		memfree(map);
		write(2, "Error\n", ft_strlen("Error\n"));
		write(2, "Incorrect map parameters\n",
			ft_strlen("Incorrect map parameters\n"));
		exit(1);
	}
	if (status == -1)
	{
		perror("Error");
		exit(1);
	}
}
