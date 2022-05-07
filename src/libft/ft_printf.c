/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:47:32 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:47:37 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;
	char	**formatstrings;
	int		i;

	formatstrings = memalloc(s);
	formatstrings = subflag(s, formatstrings);
	res = 0;
	i = -1;
	va_start(ap, s);
	printall(ap, s, formatstrings, &res);
	while (formatstrings[++i])
		free(formatstrings[i]);
	free(formatstrings);
	va_end(ap);
	return (res);
}

int	flagnum(const char *s)
{
	int	res;
	int	trigger;

	res = 0;
	trigger = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1) == '%' && trigger == 0)
		{
			s += 2;
			res++;
		}
		if (*s == '%' && trigger == 0)
		{
			trigger = 1;
			s++;
		}
		if (trigger == 1 && validateflag(*s) == 1)
		{
			res++;
			trigger = 0;
		}
		s++;
	}
	return (res);
}

char	*findformat(const char *s, char *str, int *index)
{
	int	j;
	int	trigger;
	int	i;

	j = 0;
	trigger = 0;
	i = *index;
	while (s[i])
	{
		if (s[i] == '%')
		{
			str[j++] = '%';
			i++;
			trigger = 1;
			while (validateflag(s[i]) == 0 && trigger == 1)
				str[j++] = s[i++];
			if (validateflag(s[i]) == 1 && trigger == 1)
				str[j] = s[i];
		}
		if (validateflag(s[i]) == 1 && trigger == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (str);
}

int	findfieldwidth(const char *s)
{
	int	num;
	int	trigger;

	num = 0;
	trigger = 0;
	while (*s)
	{
		if ((*s == ' ' || *s == '.' || validateflag(*s) == 1) && trigger == 1)
			break ;
		if ((*s == '%' || *s == '0' || *s == '#' || *s == ' '
				|| *s == '-' || *s == '+')
			&& (*(s + 1) <= '9' && *(s + 1) >= '1'))
			trigger = 1;
		if ((*s >= '0' && *s <= '9') && trigger == 1)
		{
			num = num * 10;
			num += *s - 48;
		}
		s++;
	}
	return (num);
}
