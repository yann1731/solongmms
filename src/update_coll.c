#include "../include/so_long.h"

void	update_coll(t_player *player, int x, int y)
{
	my_mlx_put_img(&player->vars, &player->s_o_coll, (x * 32), (y * 32));
	player->map[y][x] = 'F';
	player->held_collectibles++;
}