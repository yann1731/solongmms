/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:49:27 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:49:30 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	printhex(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.sharp == 1 && format.minus == 0)
		printhexsharp(format, nbr, base, res);
	if (format.sharp == 0 && format.minus == 0)
		printhexreg(format, nbr, res);
	if (format.minus == 1)
		printhexminusopt(format, nbr, base, res);
	if (format.sharp == 1 && format.dot == 0
		&& format.fieldwidth == 0 && format.minus == 0 && nbr != 0)
		printox(base, res);
	ft_putnbr_base_bonus(format, nbr, base, res);
	if (format.minus == 1)
		printhexminus(format, nbr, res);
}

int	memsizebase(long long n)
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
		n /= 16;
	}
	return (i);
}

int	memsizebaseuns(unsigned long long n)
{
	long long	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	printhexminus(t_flags format, unsigned int nbr, int *res)
{
	if (format.dot == 0 && format.fieldwidth > 0 && format.sharp == 0)
		while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 0 && format.fieldwidth > 0 && format.sharp == 1)
		while ((--format.fieldwidth - memsizebase(nbr) - 2) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0
		&& (format.dotfield > memsizebaseuns(nbr)) && nbr != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0
		&& (format.dotfield < memsizebaseuns(nbr)) && nbr != 0)
		while ((--format.fieldwidth - memsizebaseuns(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0
		&& (format.dotfield < memsizebaseuns(nbr)) && nbr == 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 1)
		while ((--format.fieldwidth - format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
}

void	printhexminusopt(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 1 && format.sharp == 0)
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.sharp == 1)
	{
		printox(base, res);
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 0 && format.sharp == 1)
		printox(base, res);
}
