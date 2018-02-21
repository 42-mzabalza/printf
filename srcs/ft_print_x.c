/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:18:53 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 22:17:44 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_widthpadding(char *content, t_prefix *prefix, char *val)
{
	int rtn;
	int w;

	w = prefix->width;
	if ((ft_strchr(content, '#')) && *val != '0')
		w -= 2;
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
	int p;

	p = prefix->precision;
	while (p-- > 0)
		ft_putchar('0');
	return (prefix->precision);
}

static void	ft_showx(intmax_t nb, char *str, char x, char *content)
{
	int i;

	i = 0;
	if (nb == 0 && ft_strchr(content, '.'))
		return ;
	while (str[i])
	{
		if (x == 'X' && (str[i] >= 97 && str[i] <= 122))
			str[i] -= 32;
		ft_putchar(str[i]);
		i++;
	}
}

static int	ft_prefix(char x)
{
	ft_putchar('0');
	if (x == 'X')
		ft_putchar('X');
	else
		ft_putchar('x');
	return (2);
}

int			ft_print_x(intmax_t nb, char *content, t_prefix *prefix)
{
	char	*val;
	int		len;

	val = ft_uimaxtoa_base(nb, 16);
	len = ft_strlen(val);
	if (nb == 0 && ft_strchr(content, '.'))
		len = 0;
	prefix->precision = ft_pstv(prefix->precision - len);
	prefix->width = ft_pstv(prefix->width - len - prefix->precision);
	if (nb == 0)
		prefix->hash = 0;
	if (prefix->hash && prefix->zero && !ft_strchr(content, '.'))
		prefix->rtn += ft_prefix(content[ft_strlen(content) - 1]);
	if (prefix->hash && prefix->zero && !ft_strchr(content, '.'))
		prefix->hash = 0;
	if (!(prefix->left))
		prefix->rtn += ft_widthpadding(content, prefix, val);
	if (prefix->hash)
		prefix->rtn += ft_prefix(content[ft_strlen(content) - 1]);
	prefix->rtn += ft_precisionpadding(prefix) + len;
	ft_showx(nb, val, content[ft_strlen(content) - 1], content);
	if ((prefix->left))
		prefix->rtn += ft_widthpadding(content, prefix, val);
	free(val);
	return (prefix->rtn);
}
