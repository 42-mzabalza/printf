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

static int	ft_widthpadding(char *content, t_prefix *prefix, char *val)
{
	int rtn;
	int w;

	w = prefix->width;
	if ((ft_strchr(content, '#')) && *val != '0')
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

static int	ft_precisionpadding(char *content, t_prefix *prefix, char *val)
{
	int rtn;
	int p;

	p = prefix->precision;
	if ((ft_strchr(content, '#')) && *val != '0')
		p--;
	rtn = ft_pstv(p);
	while (p-- > 0)
		ft_putchar('0');
	return (rtn);
}

static void	ft_showo(char *str, char *content)
{
	if (ft_atoi(str) == 0 && ft_strchr(content, '.'))
		return ;
	if (ft_atoi(str) == 0 && ft_strchr(content, '#'))
		return ;
	ft_putstr(str);
}

int			ft_print_o(intmax_t nb, char *content, t_prefix *prefix)
{
	char	*val;
	int		len;

	val = ft_uimaxtoa_base(nb, 8);
	len = ft_strlen(val);
	if (nb == 0 && (ft_strchr(content, '.') || ft_strchr(content, '#')))
		len = 0;
	prefix->rtn += len;
	prefix->precision = ft_pstv(prefix->precision - len);
	prefix->width = ft_pstv(prefix->width - len - prefix->precision);
	if (ft_strchr(content, '#'))
		prefix->rtn++;
	if (!(prefix->left))
		prefix->rtn += ft_widthpadding(content, prefix, val);
	if (ft_strchr(content, '#'))
		ft_putchar('0');
	prefix->rtn += ft_precisionpadding(content, prefix, val);
	ft_showo(val, content);
	if ((prefix->left))
		prefix->rtn += ft_widthpadding(content, prefix, val);
	free(val);
	return (prefix->rtn);
}
