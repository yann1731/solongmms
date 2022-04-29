#include "../include/so_long.h"

unsigned int    get_colors(t_data *data, int x, int y)
{
    char    *dst;

    // regarder pour proteger si out of windows return noir
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    return(*(unsigned int*)dst);
}