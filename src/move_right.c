#include "../include/so_long.h"

void	move_right(t_player *player)
{
	//mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, player->vars.win);
	player->x_pos += 1;
	player->steps += 1;
	printf("Steps: %d\n", player->steps);
}