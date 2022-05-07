/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_utilstwo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:48:52 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:48:55 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	dotfield(const char *s)
{
	int	num;
	int	trigger;

	num = 0;
	trigger = 0;
	while (*s)
	{
		s++;
		if ((*s == '-' || *s == ' ' || *s == '.'
				|| validateflag(*s) == 1) && trigger == 1)
			break ;
		if (*s == '.')
		{
			trigger = 1;
			s++;
		}
		if ((*s >= '0' && *s <= '9') && trigger == 1)
		{
			num = num * 10;
			num += *s - 48;
		}
	}
	return (num);
}

void	parseformat(t_flags format, char *str, va_list ap, int *res)
{
	format = popstructone(str, format);
	format = popstructtwo(str, format);
	printformat(format, ap, res);
}

void	printchar(int c, int *res)
{
	*res += write(1, &c, 1);
}

void	ft_putchar(t_flags format, int c, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0)
		while (--format.fieldwidth > 0)
			*res += write(1, " ", 1);
	*res += write(1, &c, 1);
	if (format.fieldwidth > 0 && format.minus == 1)
		while (--format.fieldwidth > 0)
			*res += write(1, " ", 1);
}
