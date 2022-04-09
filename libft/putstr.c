#include "libft.h"

void	ft_putstr_bonus(t_flags format, char *s, int *res)
{
	if (s == NULL)
		ft_putstrnull(format, res);
	else if (s != NULL)
	{
		ft_putstrtwo(format, s, res);
		if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 0)
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
		if (format.fieldwidth > 0 && format.minus == 1
			&& format.dot == 1 && format.dotfield < ft_strlen(s))
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
		if (format.fieldwidth > 0 && format.minus == 1
			&& format.dot == 1 && format.dotfield >= ft_strlen(s))
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
	}
}

void	ft_putstrnull(t_flags format, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0)
		while ((--format.fieldwidth - 6) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 0 || (format.dot == 1 && format.dotfield > 6))
		*res += write(1, "(null)", 6);
	if (format.dot == 1 && format.dotfield <= 6)
		*res += write(1, "(null)", format.dotfield);
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - 6) >= 0)
			*res += write(1, " ", 1);
}

void	ft_putstrtwo(t_flags format, char *s, int *res)
{
	int	i;

	i = -1;
	if (format.fieldwidth > 0 && format.minus == 0 && format.dot == 0)
		while ((--format.fieldwidth - ft_strlen(s)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
		while ((--format.fieldwidth - ft_strlen(s) - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1)
		while ((++i < format.dotfield) && s[i] != '\0')
			*res += write(1, &s[i], 1);
	else
		*res += write(1, s, ft_strlen(s));
}

