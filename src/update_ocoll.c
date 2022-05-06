#include "../include/so_long.h"

void	update_ocoll(t_player *player, int x, int y)
{
	my_mlx_put_img(&player->vars, &player->s_floor, (x * 32), (y * 32));
	my_mlx_put_img(&player->vars, &player->s_o_coll, (x * 32), (y * 32));
}