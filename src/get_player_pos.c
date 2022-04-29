#include "../include/so_long.h"
//Finds player position and stores it into y_pos and x_pos
void	get_player_pos(char **map, int *y_pos, int *x_pos)
{
	*x_pos = 0;
	*y_pos = 0;
	while (map[*y_pos])
	{
		while (map[*y_pos][*x_pos])
		{
			if (map[*y_pos][*x_pos] == 'P')
				return ;
			*x_pos += 1;
		}
	*y_pos += 1;
	*x_pos = 0;
	}
}