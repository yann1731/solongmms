#include "../include/so_long.h"

int	render(t_player *player)
{
	my_mlx_put_img(&player->vars,
		&player->s_pimg, (player->x_pos * 32), (player->y_pos * 32));
	if (player->map[player->y_pos][player->x_pos] == 'E')
	{
		if (player->held_collectibles == player->max_collectibles)
		{
			printf("GG!!\n");
			exit(1);
		}
	}
	mlx_hook(player->vars.win, ON_KEYDOWN, 0, move_player, player);
	return (0);
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
			if (player->map[y][x] == 'C')
				my_mlx_put_img(&player->vars, &player->s_coll, (x * 32), (y * 32));
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

