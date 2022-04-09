#include "libft.h"

void	printhexreg(t_flags format, unsigned int nbr, int *res)
{
	if (format.dot == 1 && format.fieldwidth == 0)
		while (--format.dotfield - memsizebase(nbr) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.fieldwidth > 0)
		printhexregdot(format, nbr, res);
	if (format.dot == 0 && format.fieldwidth > 0)
	{
		if (format.zero == 0)
			while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
				*res += write(1, " ", 1);
		if (format.zero == 1)
			while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
				*res += write(1, "0", 1);
	}
}

void	printhexregdot(t_flags format, unsigned int nbr, int *res)
{
	if (format.dotfield > memsizebase(nbr) && nbr != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dotfield < memsizebase(nbr) && nbr != 0)
		while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (nbr == 0 && format.fieldwidth > format.dotfield)
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
	while ((--format.dotfield - memsizebase(nbr)) >= 0)
		*res += write(1, "0", 1);
}

void	printhexsharp(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 1 && format.fieldwidth == 0)
	{
		printox(base, res);
		while ((--format.dotfield - numsize(nbr) - 2) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 1 && format.fieldwidth > 0 && format.minus == 0)
	{
		while ((--format.fieldwidth - format.dotfield - numsize(nbr) - 2) >= 0)
			*res += write(1, " ", 1);
		printox(base, res);
		while (--format.dotfield - numsize(nbr) - 2)
			*res += write(1, "0", 1);
	}
	printhexsharptwo(format, nbr, base, res);
}

void	printhexsharptwo(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 0 && format.fieldwidth > 0
		&& format.minus == 0 && format.zero == 0)
	{
		while ((--format.fieldwidth - numsize(nbr) - 2) >= 0)
				*res += write(1, " ", 1);
		printox(base, res);
	}
	if (format.dot == 0 && format.fieldwidth > 0
		&& format.minus == 0 && format.zero == 1)
	{
		printox(base, res);
		while ((--format.fieldwidth - numsize(nbr) - 2) >= 0)
			*res += write(1, "0", 1);
	}
}

void	printox(char *base, int *res)
{
	*res += write(1, "0", 1);
	if (base[10] == 'a')
		*res += write(1, "x", 1);
	else
		*res += write(1, "X", 1);
}
