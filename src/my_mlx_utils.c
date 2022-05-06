/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:39:53 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/06 18:39:57 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	my_mlx_put_img(t_vars *vars, t_data *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, x, y);
}

void	my_xpm_file_to_image(char *pathtoimg, t_vars vars, t_data *img)
{
	char	*prefix;
	char	*asset;

	prefix = ft_strdup("../assets/");
	asset = ft_strjoin(prefix, pathtoimg);
	img->img = mlx_xpm_file_to_image(vars.mlx,
			asset, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	free(prefix);
	free(asset);
}
