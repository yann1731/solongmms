#include "../include/so_long.h"

void	my_get_data_addr(t_data *img)
{
	mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
}
