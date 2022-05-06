#include "../include/so_long.h"

void	move_down(t_player *player)
{
	player->y_pos += 1;
	player->steps += 1;
	printf("Steps: %d\n", player->steps);
}