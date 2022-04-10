#include "../include/so_long.h"

void	checkarg(int argc)
{
	if (argc != 2)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		write(2, "Needs map file as input\n", ft_strlen("Needs map file as input\n"));
		exit(1);
	}
}