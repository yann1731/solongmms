#include "../include/so_long.h"

void	replace_p(t_player *player)
{
	int	y;
	int	x;

	y = player->y_pos;
	x = player->x_pos;
	player->map[y][x] = '0';
}

void	render_floor(t_player *player)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	replace_p(player);
	while (player->map[y])
	{
		while (player->map[y][x])
		{
			if (player->map[y][x] == '0' || player->map[y][x] == 'C' || player->map[y][x] == 'E')
				mlx_put_image_to_window(player->vars.mlx, player->vars.win, player->s_floor.img, (x * 32), (y * 32));
			if (player->map[y][x] == 'E')
				mlx_put_image_to_window(player->vars.mlx, player->vars.win, player->s_exit.img, (x * 32), (y * 32));
			x++;
		}
		y++;
		x = 0;
	}
}

void	render_walls(t_player *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (player->map[y])
	{
		while (player->map[y][x])
		{
			if (player->map[y][x] == '1')
				mlx_put_image_to_window(player->vars.mlx,
					player->vars.win, player->wall.img, (x * 32), (y * 32));
			x++;
		}
		y++;
		x = 0;
	}
}

int	move_player(int keycode, t_player *player)
{
	int		x;
	int		y;
	char	**map;

	x = player->x_pos;
	y = player->y_pos;
	map = player->map;
	if (keycode == ESC)
		closeprogram(player);
	if (keycode == UPKEY && map[y - 1][x] != '1')
		move_up(player);
	if (keycode == DOWNKEY && map[y + 1][x] != '1')
		move_down(player);
	if (keycode == LEFTKEY && map[y][x - 1] != '1')
		move_left(player);
	if (keycode == RIGHTKEY && map[y][x + 1] != '1')
		move_right(player);
	return (0);
}

//Similar to player_init but will init different images to be used for walls, floors etc aswell as the size of the map
//given as x and y

int	render(t_player *player)
{
	my_mlx_put_img(&player->vars, &player->s_pimg, (player->x_pos * 32), (player->y_pos * 32));
	mlx_hook(player->vars.win, ON_KEYDOWN, 0, move_player, player);
	return (0);
}

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
