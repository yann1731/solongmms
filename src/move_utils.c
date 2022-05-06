/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:33:13 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/06 18:33:16 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	move_player(int keycode, t_player *player)
{
	int		x;
	int		y;
	char	**map;

	x = player->x_pos;
	y = player->y_pos;
	map = player->map;
	if (keycode == ESC)
		closeprogram(player);
	if (keycode == UPKEY && map[y - 1][x] != '1')
		move_up(player);
	if (keycode == DOWNKEY && map[y + 1][x] != '1')
		move_down(player);
	if (keycode == LEFTKEY && map[y][x - 1] != '1')
		move_left(player);
	if (keycode == RIGHTKEY && map[y][x + 1] != '1')
		move_right(player);
	return (0);
}

void	move_down(t_player *player)
{
	int	y;
	int	x;

	y = player->y_pos;
	x = player->x_pos;
	if (player->map[y][x] == '0')
		my_mlx_put_img(&player->vars, &player->s_floor, (x * 32), (y * 32));
	if (player->map[y][x] == 'E')
		update_exit(player, x, y);
	if (player->map[y][x] == 'C')
		update_coll(player, x, y);
	if (player->map[y][x] == 'F')
		update_ocoll(player, x, y);
	player->y_pos += 1;
	player->steps += 1;
	printf("Steps: %d\n", player->steps);
}

void	move_left(t_player *player)
{
	int	y;
	int	x;

	y = player->y_pos;
	x = player->x_pos;
	if (player->map[y][x] == '0')
		my_mlx_put_img(&player->vars, &player->s_floor, (x * 32), (y * 32));
	if (player->map[y][x] == 'E')
		update_exit(player, x, y);
	if (player->map[y][x] == 'C')
		update_coll(player, x, y);
	if (player->map[y][x] == 'F')
		update_ocoll(player, x, y);
	player->x_pos -= 1;
	player->steps += 1;
	printf("Steps: %d\n", player->steps);
}

void	move_right(t_player *player)
{
	int	y;
	int	x;

	y = player->y_pos;
	x = player->x_pos;
	if (player->map[y][x] == '0')
		my_mlx_put_img(&player->vars, &player->s_floor, (x * 32), (y * 32));
	if (player->map[y][x] == 'E')
		update_exit(player, x, y);
	if (player->map[y][x] == 'C')
		update_coll(player, x, y);
	if (player->map[y][x] == 'F')
		update_ocoll(player, x, y);
	player->x_pos += 1;
	player->steps += 1;
	printf("Steps: %d\n", player->steps);
}

void	move_up(t_player *player)
{
	int	y;
	int	x;

	y = player->y_pos;
	x = player->x_pos;
	if (player->map[y][x] == '0')
		my_mlx_put_img(&player->vars, &player->s_floor, (x * 32), (y * 32));
	if (player->map[y][x] == 'E')
		update_exit(player, x, y);
	if (player->map[y][x] == 'C')
		update_coll(player, x, y);
	if (player->map[y][x] == 'F')
		update_ocoll(player, x, y);
	player->y_pos -= 1;
	player->steps += 1;
	printf("Steps: %d\n", player->steps);
}
