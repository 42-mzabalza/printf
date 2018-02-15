/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:47:30 by mzabalza          #+#    #+#             */
/*   Updated: 2018/01/23 22:50:05 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_undigits(uintmax_t nb)
{
	int			ndigits;

	ndigits = 1;
	while (nb >= 10)
	{
		nb /= 10;
		ndigits++;
	}
	return (ndigits);
}
