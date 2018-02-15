/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:18:53 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 15:03:10 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_widthpadding(t_prefix *prefix)
{
	int rtn;
	int w;

	w = prefix->width;
	rtn = ft_pstv(w);
	while (w-- > 0)
	{
		if (prefix->zero && !prefix->left)
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

static void	ft_showb(char *str, char *content)
{
	if (ft_atoi(str) == 0 && ft_strchr(content, '.'))
		return ;
	ft_putstr(str);
}

int			ft_print_b(intmax_t nb, char *content, t_prefix *prefix)
{
	char	*val;
	int		len;

	val = ft_uimaxtoa_base(nb, 2);
	len = ft_strlen(val);
	if (nb == 0 && ft_strchr(content, '.'))
		len = 0;
	prefix->rtn += len;
	prefix->precision = ft_pstv(prefix->precision - len);
	prefix->width = ft_pstv(prefix->width - len - prefix->precision);
	if (!(prefix->left))
		prefix->rtn += ft_widthpadding(prefix);
	prefix->rtn += ft_precisionpadding(prefix);
	ft_showb(val, content);
	if ((prefix->left))
		prefix->rtn += ft_widthpadding(prefix);
	free(val);
	return (prefix->rtn);
}
