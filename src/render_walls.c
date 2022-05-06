#include "../include/so_long.h"

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
