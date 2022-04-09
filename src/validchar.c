#include "../include/so_long.h"

int	validchar(char c)
{
	if (c != '1' || c != '0' || c != 'C' || c != 'E' || c != 'P')
		return (0);
	return (1);
}