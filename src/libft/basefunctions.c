/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:46:39 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:46:44 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	validateflag(int c)
{
	if (c != 'c' && c != 's' && c != 'd' && c != 'i' && c != 'u'
		&& c != 'p' && c != 'x' && c != 'x' && c != 'X' && c != '%')
		return (0);
	return (1);
}

char	**subflag(const char *s, char **str)
{
	int	iter;
	int	limit;
	int	index;

	iter = -1;
	limit = flagnum(s);
	index = 0;
	while (++iter < limit)
		str[iter] = findformat(s, str[iter], &index);
	return (str);
}

int	stringlen(const char *s, int *index)
{
	int	i;
	int	res;
	int	trigger;

	i = *index;
	res = 0;
	trigger = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			trigger = 1;
			while (validateflag(s[++i]) == 0)
				res++;
		}
		if (validateflag(s[i]) == 1 && trigger == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (res + 1);
}

void	printformat(t_flags format, va_list ap, int *res)
{
	if (format.flag == 'c')
		ft_putchar(format, va_arg(ap, int), res);
	if (format.flag == 's')
		ft_putstr_bonus(format, va_arg(ap, char *), res);
	if (format.flag == 'd')
		printnumberone(format, va_arg(ap, int), res);
	if (format.flag == 'p')
		printpointer(format, va_arg(ap, void *), res);
	if (format.flag == 'i')
		printnumberone(format, va_arg(ap, int), res);
	if (format.flag == 'u')
		printunsigned(format, va_arg(ap, unsigned int), res);
	if (format.flag == 'x')
		printhex(format, va_arg(ap, unsigned int), "0123456789abcdef", res);
	if (format.flag == 'X')
		printhex(format, va_arg(ap, unsigned int), "0123456789ABCDEF", res);
	if (format.flag == '%')
		printpercent(format, res);
}
