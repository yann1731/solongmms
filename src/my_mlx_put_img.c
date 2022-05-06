#include "../include/so_long.h"

void	my_mlx_put_img(t_vars *vars, t_data *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, x, y);
}
