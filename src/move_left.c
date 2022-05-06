#include "../include/so_long.h"

void	move_left(t_player *player)
{
	int	y;
	int x;

	y = player->y_pos;
	x = player->x_pos;
	if (map[y][x] == '0')
		my_mlx_put_img(&player->vars, )
	player->x_pos -= 1;
	player->steps += 1;
	printf("Steps: %d\n", player->steps);
}