/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:51:35 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:51:39 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_base_bonus(t_flags format, unsigned int nbr,
			char *base, int *res)
{	
	if (nbr == 0 && format.dot == 1 && format.dotfield == 0)
		return ;
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16)
		printchar(base[nbr], res);
}
