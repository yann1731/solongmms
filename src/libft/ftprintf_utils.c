#include "libft.h"

t_flags	initstruct(t_flags format)
{
	format.dot = 0;
	format.dotfield = 0;
	format.flag = 0;
	format.minus = 0;
	format.plus = 0;
	format.sharp = 0;
	format.space = 0;
	format.zero = 0;
	format.fieldwidth = 0;
	return (format);
}

char	**memalloc(const char *s)
{
	char	**rstr;
	int		res;
	int		index;
	int		i;
	int		mem;

	i = -1;
	index = 0;
	res = flagnum(s);
	rstr = malloc((res + 1) * sizeof(char *));
	while (++i < res)
	{
		mem = stringlen(s, &index);
		rstr[i] = malloc((mem + 2) * sizeof(char));
		ft_memset(rstr[i], '\0', (mem + 2));
	}
	rstr[i] = NULL;
	return (rstr);
}

t_flags	popstructone(const char *s, t_flags format)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			format.minus = 1;
		if (s[i] == '0' && s[i - 1] != '.' && (s[i - 1] == '%'
				|| s[i - 1] == '#' || s[i - 1] == ' '
				|| s[i - 1] == '-' || s[i - 1] == '+'))
			format.zero = 1;
		if (s[i] == '.')
		{
			format.dot = 1;
			format.dotfield = dotfield(s);
		}
	i++;
	}
	return (format);
}

t_flags	popstructtwo(const char *s, t_flags format)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			format.fieldwidth = findfieldwidth(s);
		if (s[i] == '+')
			format.plus = 1;
		if (s[i] == '#')
			format.sharp = 1;
		if (s[i] == ' ')
			format.space = 1;
		if (validateflag(s[i]) == 1)
			format.flag = s[i];
		i++;
	}
	return (format);
}

void	printall(va_list ap, const char *s, char **formatstrings, int *res)
{
	t_flags	format;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == '%')
		{
			format = initstruct(format);
			parseformat(format, formatstrings[i], ap, res);
			j += ft_strlen(formatstrings[i]);
			i++;
			if (s[j] == '\0')
				break ;
		}
		if (s[j] == '\0')
			break ;
		if (s[j] != '%')
			printchar(s[j], res);
		j++;
	}
}