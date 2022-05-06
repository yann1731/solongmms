#include "../include/so_long.h"

void	move_up(t_player *player)
{
	//mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, player->vars.win);
	player->y_pos -= 1;
	player->steps += 1;
	printf("Steps: %d\n", player->steps);
}