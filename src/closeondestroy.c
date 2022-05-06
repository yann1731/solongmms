#include "../include/so_long.h"

int	closeondestroy(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
