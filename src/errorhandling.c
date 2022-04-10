#include "../include/so_long.h"

void	errorhandling(int status)
{
	if (status == 0)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		write(2, "Incorrect map parameters\n", ft_strlen("Incorrect map parameters\n"));
		exit(1);
	}
}