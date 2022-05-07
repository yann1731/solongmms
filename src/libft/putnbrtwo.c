/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrtwo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:52:04 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:52:08 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	printnumberthree(t_flags format, int n, int *res)
{
	if (format.space == 1 || format.plus == 1)
		printnumsign(format, n, res);
	else
	{
		if (n < 0 && (format.dotfield > numsize(n)))
			while ((--format.fieldwidth - format.dotfield - 1) >= 0)
				*res += write(1, " ", 1);
		if (n < 0 && (format.dotfield < numsize(n)))
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
		if (n < 0)
			*res += write(1, "-", 1);
		if (n > 0 && (format.dotfield >= numsize(n)))
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
		else if (n > 0 && (numsize(n) > format.dotfield))
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
		if (n == 0 && format.fieldwidth > 0)
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
	}
	while ((--format.dotfield - numsizedot(n)) >= 0)
		*res += write(1, "0", 1);
}

void	printnumsign(t_flags format, int n, int *res)
{
	while ((--format.fieldwidth - format.dotfield - 1) >= 0)
		*res += write(1, " ", 1);
	if (n >= 0 && format.plus == 1)
		*res += write(1, "+", 1);
	else if (n >= 0 && format.space == 1)
		*res += write(1, " ", 1);
	else if (n < 0 && (format.space == 1 || format.plus == 1))
		*res += write(1, "-", 1);
}

void	printnumminus(t_flags format, int n, int *res)
{
	if (format.plus == 1 || format.space == 1)
	{
		if (format.plus == 1 && n >= 0)
			*res += write(1, "+", 1);
		if (format.space == 1 && format.plus != 1 && n >= 0)
			*res += write(1, " ", 1);
	}
	if (n < 0)
		*res += write(1, "-", 1);
	if (format.dot == 1)
		while ((--format.dotfield - numsizedot(n)) >= 0)
			*res += write(1, "0", 1);
}

void	printnumminustwo(t_flags format, int n, int *res)
{
	if (format.minus == 1 && format.fieldwidth > 0 && format.dot == 0)
	{
		if (format.plus == 0 && format.space == 0)
			while (--format.fieldwidth - numsize(n) >= 0)
				*res += write(1, " ", 1);
		if ((format.plus == 1 || format.space == 1) && n >= 0)
			while (--format.fieldwidth - numsize(n) > 0)
				*res += write(1, " ", 1);
		if ((format.plus == 1 || format.space == 1) && n < 0)
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
	}
	if (format.minus == 1 && format.fieldwidth > 0 && format.dot == 1)
		printnumminusthree(format, n, res);
}

void	printnumminusthree(t_flags format, int n, int *res)
{
	if (format.plus == 0 && format.space == 0
		&& n > 0 && (format.dotfield > numsize(n)))
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.plus == 0 && format.space == 0
		&& n > 0 && (format.dotfield < numsize(n)))
		while ((--format.fieldwidth - numsize(n) >= 0))
			*res += write(1, " ", 1);
	if (format.plus == 0 && format.space == 0 && n < 0)
		while ((--format.fieldwidth - format.dotfield) > 0)
			*res += write(1, " ", 1);
	if (format.plus == 1 || format.space == 1)
		while ((--format.fieldwidth - format.dotfield) > 0)
			*res += write(1, " ", 1);
	if (n == 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
}
