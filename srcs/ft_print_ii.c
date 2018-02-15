/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:55:51 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 14:40:07 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putsign(long val, t_prefix *prefix)
{
	int rtn;

	rtn = 0;
	if (prefix->sign && val >= 0)
	{
		ft_putchar('+');
		rtn++;
	}
	if (val < 0)
	{
		ft_putchar('-');
		rtn++;
	}
	return (rtn);
}

static int		ft_widthpadding(t_prefix *prefix, intmax_t val, char *content)
{
	int w;
	int rtn;

	w = prefix->width;
	if (prefix->sign || val < 0)
		w--;
	rtn = ft_pstv(w);
	while (w-- > 0)
	{
		if (prefix->zero && !prefix->left && !ft_strchr(content, '.'))
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	return (rtn);
}

static int		ft_precisionpadding(t_prefix *prefix)
{
	int p;
	int rtn;

	p = prefix->precision;
	rtn = p;
	while (p-- > 0)
		ft_putchar('0');
	return (rtn);
}

static intmax_t	ft_abs2(intmax_t nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int				ft_print_ii(intmax_t val, char *content, t_prefix *prefix)
{
	prefix->precision = ft_pstv(prefix->precision - ft_ndigits(val));
	prefix->width = ft_pstv(prefix->width - ft_ndigits(val));
	prefix->width = ft_pstv(prefix->width - prefix->precision);
	if (prefix->zero && prefix->width)
		prefix->rtn += ft_putsign(val, prefix);
	ft_ispaceflag(content, val, &prefix);
	if (!(prefix->left))
		prefix->rtn += ft_widthpadding(prefix, val, content);
	if (!prefix->zero || (prefix->zero && !prefix->width))
		prefix->rtn += ft_putsign(val, prefix);
	prefix->rtn += ft_precisionpadding(prefix);
	if (val == 0 && ft_strchr(content, '.') &&
			prefix->precision == 0 && prefix->width)
		ft_putchar(' ');
	if (!(val == 0 && ft_strchr(content, '.') && prefix->precision == 0))
		ft_putmaxuint(ft_abs2(val));
	if ((prefix->left))
		prefix->rtn += ft_widthpadding(prefix, val, content);
	if (!(val == 0 && ft_strchr(content, '.') && prefix->width == 0))
		prefix->rtn += ft_ndigits(val);
	return (prefix->rtn);
}
