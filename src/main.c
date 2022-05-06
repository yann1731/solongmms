#include "../include/so_long.h"

int main(int argc, char *argv[])
{
	t_player	player;
	char		**map;
	t_data		s_img;

	checkarg(argc);
	map = convertmaptostring(argv[1]);
	errorhandling(checkmap(map));
	player_init(&player, map);
	render_walls(&player);
	render_floor(&player);
	mlx_loop_hook(player.vars.mlx, &render, &player);
	mlx_loop(player.vars.mlx);
	
	return (0);
}
