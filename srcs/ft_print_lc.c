/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:49:22 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 21:58:34 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long		ft_dectobin(int nb)
{
	long nbin;
	long i;

	nbin = 0;
	i = 1;
	while (nb >= 2)
	{
		nbin += (nb % 2) * i;
		nb /= 2;
		i *= 10;
	}
	nbin += (nb) * i;
	return (nbin);
}

int			ft_bintodec(long bin)
{
	int dec;
	int i;

	i = 0;
	dec = 0;
	while (bin > 0)
	{
		if (bin % 10)
			dec += ft_pow(((bin % 10) * 2), i);
		i++;
		bin /= 10;
	}
	return (dec);
}

int			ft_utf8(long *bin, int i)
{
	int dst;

	dst = '\0';
	if (i)
	{
		dst = 10000000 + (*bin - ((*bin / 1000000) * 1000000));
		*bin /= 1000000;
	}
	return (dst);
}

int			ft_print_lc(va_list vlist)
{
	int		val;
	int		bytes;
	char	*dst;
	long	bin;
	int		i;

	bytes = 11110;
	val = va_arg(vlist, int);
	if (val <= 127)
		return (write(1, &val, 1));
	if (val <= 127 || val >= 2097151)
		return (0);
	else if (val < 2047)
		bytes = 110;
	else if (val < 65535)
		bytes = 1110;
	bin = ft_dectobin(val);
	dst = (char *)malloc(sizeof(char) * ft_ndigits(bytes) - 1);
	i = ft_ndigits(bytes) - 1;
	while (i-- > 1)
		dst[i] = ft_bintodec(ft_utf8(&bin, i));
	dst[0] = ft_bintodec((bytes * (ft_pow(10, 8 - ft_ndigits(bytes)))) + bin);
	i = write(1, dst, ft_strlen(dst));
	free(dst);
	return (i);
}
