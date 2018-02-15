/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:00:55 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 22:11:46 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_widthpadding(t_prefix *prefix, char *content)
{
	int w;
	int rtn;

	w = prefix->width;
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

static int		ft_showp(char *content, char *dst, void *val)
{
	if (ft_strchr(content, '.') && val == 0)
		return (0);
	ft_putstr(dst);
	return (ft_strlen(dst));
}

int				ft_print_p(va_list vlist, char *content, t_prefix *prefix)
{
	void		*val;
	intmax_t	p;
	char		*dst;
	int			len;

	val = va_arg(vlist, void *);
	p = (intmax_t)val;
	dst = ft_imaxtoa_base(p, 16);
	len = ft_strlen(dst);
	if (val == 0 && ft_strchr(content, '.'))
		len = 0;
	prefix->precision = ft_pstv(prefix->precision - len);
	prefix->width = ft_pstv(prefix->width - len - 2 - prefix->precision);
	if ((prefix->zero && !ft_strchr(content, '.')))
		ft_putstr("0x");
	if (!(prefix->left))
		prefix->rtn += ft_widthpadding(prefix, content);
	if (!prefix->zero || (prefix->zero && ft_strchr(content, '.')))
		ft_putstr("0x");
	prefix->rtn += ft_precisionpadding(prefix);
	prefix->rtn += ft_showp(content, dst, val) + 2;
	if ((prefix->left))
		prefix->rtn += ft_widthpadding(prefix, content);
	free(dst);
	return (prefix->rtn);
}
