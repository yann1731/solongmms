#include "../include/so_long.h"

t_data    image_scale_init(t_data *image, float scale, void *mlx)
{
    t_data			image_scale;
    float			x;
    float			y;
    unsigned int	color;
    
    image_scale.width = image->width * scale;
    image_scale.height = image->height * scale;
    image_scale.img = mlx_new_image(mlx, image_scale.width, image_scale.height);
    image_scale.addr = mlx_get_data_addr(image_scale.img, &image_scale.bits_per_pixel, &image_scale.size_line, &image_scale.endian);
    x = 0;
    while (x < (image->width * scale))
    {
        y = 0;
        while (y < (image->height * scale))
        {
            color = get_colors(image, (x / scale), (y / scale)); // vas chercher la couleur exacte du pixel de l'image de base
            my_mlx_pixel_put(&image_scale, x, y, color); //copi la couleur prise ulterieurement et la place dans la nouvelle image
            y++;    
        }
        x++;
    }
    // destroy old image au choix donc boolean
    return(image_scale);
}

unsigned int    get_colors(t_data *data, int x, int y)
{
    char    *dst;

    // regarder pour proteger si out of windows return noir
    dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
    return(*(unsigned int*)dst);
}

void	my_get_data_addr(t_data *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->size_line, &img->endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
