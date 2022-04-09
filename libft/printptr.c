#include "libft.h"

static char	*posnumbase(unsigned long long n, char *str)
{
	size_t		max;
	const char	*base;

	base = "0123456789abcdef";
	max = memsizebaseuns(n);
	str[max] = '\0';
	while (max > 0)
	{
		str[max - 1] = base[n % 16];
		n = n / 16;
		max--;
	}
	return (str);
}

void	printpointer(t_flags format, void *ptr, int *res)
{
	char	*str;

	str = ft_itoa_base((unsigned long long) ptr);
	if (format.fieldwidth > 0 && format.minus == 0)
		while ((--format.fieldwidth - ft_strlen(str) - 2) >= 0)
			*res += write(1, " ", 1);
	*res += write(1, "0x", 2);
	*res += write(1, str, ft_strlen(str));
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - ft_strlen(str) - 2) >= 0)
			*res += write(1, " ", 1);
	free(str);
}

char	*ft_itoa_base(unsigned long long n)
{
	char	*str;
	size_t	max;

	max = memsizebaseuns(n);
	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc((max + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		str = posnumbase(n, str);
	return (str);
}