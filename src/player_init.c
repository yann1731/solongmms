#include "../include/so_long.h"
//inits the player struct with different images to be used in different frames. Also gets the starting
//position of the player in the form of x and y passed by address to get_player_pos
void	player_init(t_player *player, t_vars vars, char **map)
{
	my_xpm_file_to_image("player1.xpm", vars, &player->img1);
	my_get_data_addr(&player->img1);
	my_xpm_file_to_image("player2.xpm", vars, &player->img2);
	my_get_data_addr(&player->img2);
	my_xpm_file_to_image("player3.xpm", vars, &player->img3);
	my_get_data_addr(&player->img3);
	my_xpm_file_to_image("player4.xpm", vars, &player->img4);
	my_get_data_addr(&player->img4);
	my_xpm_file_to_image("player5.xpm", vars, &player->img5);
	my_get_data_addr(&player->img5);
	my_xpm_file_to_image("player6.xpm", vars, &player->img6);
	my_get_data_addr(&player->img6);
	get_player_pos(map, &player->y_pos, &player->x_pos);
}
