/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:18:53 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 22:02:10 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_widthpadding(char *content, t_prefix *prefix)
{
	int rtn;
	int w;

	w = prefix->width - prefix->hash;
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

static int	ft_precisionpadding(t_prefix *prefix)
{
	int rtn;
	int p;

	p = prefix->precision;
	rtn = ft_pstv(p);
	while (p-- > 0)
		ft_putchar('0');
	return (rtn);
}

static void	ft_showo(char *str, t_prefix *prefix, char *content, int nb)
{
	int i;

	i = prefix->hash;
	if (nb == 0 && ft_strchr(content, '.'))
		return ;
	ft_putstr(str);
}

int			ft_print_o(intmax_t nb, char *content, t_prefix *prefix)
{
	char	*val;
	int		len;

	val = ft_uimaxtoa_base(nb, 8);
	len = ft_strlen(val);
	if (nb == 0 && ft_strchr(content, '.'))
		len = 0;
	if (!ft_strchr(content, '.') && prefix->precision == 0 && nb == 0)
		prefix->hash = 0;
	prefix->precision = ft_pstv(prefix->precision - len - prefix->hash);
	prefix->width = ft_pstv(prefix->width - len - prefix->precision);
	if (prefix->hash)
		prefix->rtn++;
	if (!(prefix->left))
		prefix->rtn += ft_widthpadding(content, prefix);
	if (prefix->hash)
		ft_putchar('0');
	prefix->rtn += ft_precisionpadding(prefix) + len;
	ft_showo(val, prefix, content, nb);
	if ((prefix->left))
		prefix->rtn += ft_widthpadding(content, prefix);
	free(val);
	return (prefix->rtn);
}
