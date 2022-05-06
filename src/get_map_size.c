#include "../include/so_long.h"

//x and y coordinates passed by adress for values
//to be modified in accordance with the length of the map on the x axis and y axis
void	get_map_size(char **map, int *y_map, int *x_map)
{
	*y_map = 0;
	*x_map = 0;
	while (map[*y_map])
		*y_map += 1;
	while (map[0][*x_map] != '\n')
		*x_map += 1;
}