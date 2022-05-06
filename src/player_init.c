#include "../include/so_long.h"
//inits the player struct with different 
//images to be used in different frames. Also gets the starting
//position of the player in the form of
//x and y passed by address to get_player_pos
void	player_init(t_player *player, char **map)
{
	player->map = map;
	player->vars.mlx = mlx_init();
	get_map_size(player->map, &player->y_map, &player->x_map);
	player->vars.win = mlx_new_window(player->vars.mlx, (player->x_map * 32),
			(player->y_map * 32), "So long!");
	my_xpm_file_to_image("exit.xpm", player->vars, &player->exit);
	my_xpm_file_to_image("player1.xpm", player->vars, &player->pimg);
	my_xpm_file_to_image("wall.xpm", player->vars, &player->wall);
	my_xpm_file_to_image("wooden.xpm", player->vars, &player->floor);
	get_player_pos(map, &player->y_pos, &player->x_pos);
	player->s_floor = image_scale_init(&player->floor, 2.0, player->vars.mlx);
	player->s_pimg = image_scale_init(&player->pimg, 2.0, player->vars.mlx);
	player->s_exit = image_scale_init(&player->exit, 2.0, player->vars.mlx);
	player->steps = 0;
}
