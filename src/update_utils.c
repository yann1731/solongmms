#include "../include/so_long.h"

void	update_coll(t_player *player, int x, int y)
{
	my_mlx_put_img(&player->vars, &player->s_o_coll, (x * 32), (y * 32));
	player->map[y][x] = 'F';
	player->held_collectibles++;
}

void	update_exit(t_player *player, int x, int y)
{
	my_mlx_put_img(&player->vars, &player->s_floor, (x * 32), (y * 32));
	my_mlx_put_img(&player->vars, &player->s_exit, (x * 32), (y * 32));
}

void	update_ocoll(t_player *player, int x, int y)
{
	my_mlx_put_img(&player->vars, &player->s_floor, (x * 32), (y * 32));
	my_mlx_put_img(&player->vars, &player->s_o_coll, (x * 32), (y * 32));
}

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
	my_xpm_file_to_image("chest.xpm", player->vars, &player->coll);
	my_xpm_file_to_image("openchest.xpm", player->vars, &player->o_coll);
	get_player_pos(map, &player->y_pos, &player->x_pos);
	player->s_floor = image_scale_init(&player->floor, 2.0, player->vars.mlx);
	player->s_pimg = image_scale_init(&player->pimg, 2.0, player->vars.mlx);
	player->s_exit = image_scale_init(&player->exit, 2.0, player->vars.mlx);
	player->s_coll = image_scale_init(&player->coll, 2.0, player->vars.mlx);
	player->s_o_coll = image_scale_init(&player->o_coll, 2.0, player->vars.mlx);
	player->steps = 0;
	player->held_collectibles = 0;
	player->max_collectibles = checkcoll(player->map);
}
