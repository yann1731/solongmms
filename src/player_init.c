#include "../include/so_long.h"
//inits the player struct with different 
//images to be used in different frames. Also gets the starting
//position of the player in the form of
//x and y passed by address to get_player_pos
void	player_init(t_player *player, char **map)
{
	player->map = map;
	my_xpm_file_to_image("player1.xpm", player->vars, &player->pimg);
	get_player_pos(map, &player->y_pos, &player->x_pos);
	player->steps = 0;
}
