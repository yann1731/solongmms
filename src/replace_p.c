#include "../include/so_long.h"

void	replace_p(t_player *player)
{
	int	y;
	int	x;

	y = player->y_pos;
	x = player->x_pos;
	player->map[y][x] = '0';
}
