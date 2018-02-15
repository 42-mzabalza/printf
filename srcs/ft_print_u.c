/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:55:51 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 22:02:32 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_widthpadding(t_prefix *prefix)
{
	int rtn;
	int w;

	rtn = 0;
	w = prefix->width;
	rtn += w;
	while (w-- > 0)
	{
		if (prefix->zero)
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

static int	ft_showu(uintmax_t val, char *content)
{
	if (val == 0 && ft_strchr(content, '.'))
		return (0);
	ft_putmaxuint(val);
	return (ft_undigits(val));
}

int			ft_print_u(uintmax_t val, char *content, t_prefix *prefix)
{
	prefix->precision = ft_pstv(prefix->precision - ft_ndigits(val));
	prefix->width = ft_pstv(prefix->width - ft_ndigits(val));
	prefix->width = ft_pstv(prefix->width - prefix->precision);
	if (!(prefix->left))
		prefix->rtn += ft_widthpadding(prefix);
	prefix->rtn += ft_precisionpadding(prefix);
	prefix->rtn += ft_showu(val, content);
	if ((prefix->left))
		prefix->rtn += ft_widthpadding(prefix);
	return (prefix->rtn);
}
