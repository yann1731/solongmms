/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrthree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:51:49 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:51:52 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	printnumspace(t_flags format, int n, int *res)
{
	if (format.plus == 1 || format.space == 1)
		while ((--format.fieldwidth - numsizedot(n) - 1) >= 0)
			*res += write(1, " ", 1);
	else
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.plus == 1 && n >= 0)
		*res += write(1, "+", 1);
	if (format.space == 1 && n >= 0 && format.plus != 1)
		*res += write(1, " ", 1);
}

void	printnumzero(t_flags format, int n, int *res)
{
	if (format.plus == 1 && n >= 0)
				*res += write(1, "+", 1);
	if (n < 0)
		*res += write(1, "-", 1);
	if (format.space == 1 && n >= 0)
		*res += write(1, " ", 1);
	while ((--format.fieldwidth - numsizedot(n) - 1) >= 0)
		*res += write(1, "0", 1);
}
