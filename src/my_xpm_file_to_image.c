#include "../include/so_long.h"

void	my_xpm_file_to_image(char *pathtoimg, t_vars vars, t_data *img)
{
	char	*prefix = "../assets/characters/";
	prefix = ft_strjoin(prefix, pathtoimg);
	img->img = mlx_xpm_file_to_image(vars.mlx,
			prefix, &img->width, &img->height);
	free(prefix);
}
