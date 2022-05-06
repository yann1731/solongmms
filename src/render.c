#include "../include/so_long.h"

int	render(t_player *player)
{
	my_mlx_put_img(&player->vars, &player->s_pimg, (player->x_pos * 32), (player->y_pos * 32));
	if (player->map[player->y_pos][player->x_pos] == 'E')
		if (player->held_collectibles == player->max_collectibles)
			exit(1);
	mlx_hook(player->vars.win, ON_KEYDOWN, 0, move_player, player);
	return (0);
}
