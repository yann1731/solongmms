/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:50:41 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:50:45 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putuns_bonus(t_flags format, unsigned int n, int *res)
{
	if (n == 0 && format.dot == 1 && format.dotfield == 0)
		return ;
	if (n >= 10)
	{
		ft_putuns_bonus(format, n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		printchar((n + 48), res);
}

void	printunsdot(t_flags format, unsigned int n, int *res)
{
	if (format.dotfield > numsize(n) && n != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	else if (format.dotfield < numsize(n) && n != 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	else if (n == 0 && format.fieldwidth > format.dotfield)
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
	while ((--format.dotfield - numsize(n)) >= 0)
		*res += write(1, "0", 1);
}

void	printunsigned(t_flags format, unsigned int n, int *res)
{
	printunsignedtwo(format, n, res);
	ft_putuns_bonus(format, n, res);
	printunsminus(format, n, res);
}

void	printunsignedtwo(t_flags format, unsigned int n, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0
		&& format.dot == 0 && format.zero == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 0
		&& format.dot == 0 && format.zero == 1)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
		printunsdot(format, n, res);
	if (format.fieldwidth == 0 && format.dot == 1)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.minus == 1 && format.dotfield > 0)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
}

void	printunsminus(t_flags format, unsigned int n, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1
		&& format.dot == 1 && (format.dotfield < numsize(n)) && n != 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1
		&& format.dot == 1 && (format.dotfield > numsize(n)) && n != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1
		&& format.dot == 1 && n == 0 && (format.fieldwidth < format.dotfield))
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1
		&& format.dot == 1 && n == 0 && (format.fieldwidth > format.dotfield))
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
}
