/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:55:51 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/20 23:46:20 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_widthpadding(t_prefix *prefix, char *content)
{
	int rtn;
	int w;

	rtn = 0;
	w = prefix->width;
	rtn += w;
	while (w-- > 0)
	{
		if (prefix->zero && !prefix->left && !ft_strchr(content, '.'))
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	return (rtn);
}

static int	ft_precisionpadding(t_prefix *prefix)
{
	int p;

	p = prefix->precision;
	while (p-- > 0)
		ft_putchar('0');
	return (prefix->precision);
}

static int	ft_nudigits(uintmax_t val)
{
	int			ndigits;

	ndigits = 1;
	while (val >= 10)
	{
		val /= 10;
		ndigits++;
	}
	return (ndigits);
}

static int	ft_showu(uintmax_t val)
{
	ft_putmaxuint(val);
	return (ft_undigits(val));
}

int			ft_print_u(uintmax_t val, char *content, t_prefix *prefix)
{
	prefix->precision = ft_pstv(prefix->precision - ft_nudigits(val));
	prefix->width = ft_pstv(prefix->width - ft_nudigits(val));
	prefix->width = ft_pstv(prefix->width - prefix->precision);
	if (!(prefix->left))
		prefix->rtn += ft_widthpadding(prefix, content);
	prefix->rtn += ft_precisionpadding(prefix);
	if (!(val == 0 && ft_strchr(content, '.') && prefix->precision == 0))
		prefix->rtn += ft_showu(val);
	if ((prefix->left))
		prefix->rtn += ft_widthpadding(prefix, content);
	return (prefix->rtn);
}
