#include "../include/so_long.h"

void	move_up(t_player *player)
{
	int	y;
	int x;

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