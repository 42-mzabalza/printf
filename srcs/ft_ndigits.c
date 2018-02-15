/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:47:30 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 13:44:49 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	ft_abs2(intmax_t nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int				ft_ndigits(intmax_t nb)
{
	int			ndigits;
	uintmax_t	dstnb;

	dstnb = ft_abs2(nb);
	ndigits = 1;
	while (dstnb >= 10)
	{
		dstnb /= 10;
		ndigits++;
	}
	return (ndigits);
}
