#include "../include/so_long.h"

int	parsecriteria(t_criteria info)
{
	if (info.C == 1 && info.E == 1 && info.P == 1)
		return (1);
	return (0);
}