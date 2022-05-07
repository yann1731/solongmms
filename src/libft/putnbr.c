/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:51:00 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:51:05 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_bonus(t_flags format, int n, int *res)
{
	long long	nout;

	nout = (long long) n;
	if (format.dot == 1 && format.dotfield == 0 && n == 0)
		return ;
	if (nout < 0)
		nout = -nout;
	if (nout >= 10)
	{
		ft_putnbr_bonus(format, nout / 10, res);
		nout = nout % 10;
	}
	if (nout <= 9 && nout >= 0)
		printchar((nout + 48), res);
}

int	numsize(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	numsizedot(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	printnumberone(t_flags format, int n, int *res)
{
	if (format.minus == 0)
		printnumbertwo(format, n, res);
	if (format.minus == 1)
		printnumminus(format, n, res);
	if ((format.dot == 0 && format.zero == 0 && format.minus == 0)
		|| (format.zero == 1 && format.fieldwidth == 0
			&& format.minus == 0 && format.dot == 0))
		if (n < 0)
			*res += write(1, "-", 1);
	ft_putnbr_bonus(format, n, res);
	if (format.minus == 1)
		printnumminustwo(format, n, res);
}

void	printnumbertwo(t_flags format, int n, int *res)
{
	if ((format.fieldwidth > 0 || format.plus == 1 || format.space == 1)
		&& format.zero == 0 && format.dot == 0)
		printnumspace(format, n, res);
	if (format.zero == 1 && format.fieldwidth > 0
		&& format.plus == 0 && format.space == 0 && format.dot == 0)
	{
		if (n < 0)
			*res += write(1, "-", 1);
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.zero == 1 && format.fieldwidth > 0 && format.dot == 0
		&& (format.space == 1 || format.plus == 1))
		printnumzero(format, n, res);
	if (format.dot == 1)
		printnumberthree(format, n, res);
}
