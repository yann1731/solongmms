#include "../include/so_long.h"

void	my_get_data_addr(t_data *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->size_line, &img->endian);
}
