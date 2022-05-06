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
