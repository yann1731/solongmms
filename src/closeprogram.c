#include "../include/so_long.h"

void	closeprogram(t_player *player)
{
	mlx_destroy_window(player->vars.mlx, player->vars.win);
	exit(0);
}