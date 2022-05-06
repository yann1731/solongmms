#include "../include/so_long.h"

void	update_exit(t_player *player, int x, int y)
{
	my_mlx_put_img(&player->vars, &player->s_floor, (x * 32), (y * 32));
	my_mlx_put_img(&player->vars, &player->s_exit, (x * 32), (y * 32));
}