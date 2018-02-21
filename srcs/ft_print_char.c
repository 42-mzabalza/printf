/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 00:08:02 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 21:55:05 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_widthpadding(char *content, t_prefix *prefix, char s)
{
	int rtn;
	int w;

	w = ft_pstv(prefix->width - 1);
	if (ft_strchr(content, 'l') || s == 'C')
		w = ft_pstv(w - 1);
	rtn = w;
	while (w-- > 0)
		if (prefix->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
	return (rtn);
}

int			ft_print_char(va_list v, char *content, t_prefix *prefix, char s)
{
	int i;

	if (!prefix->left)
		prefix->rtn += ft_pstv(ft_widthpadding(content, prefix, s));
	if (ft_strchr(content, 'l') || s == 'C')
	{
		i = ft_print_lc(v);
		if (i == -1)
			return (-1);
		prefix->rtn += i;
	}
	else
	{
		ft_print_c(v);
		prefix->rtn++;
	}
	if (prefix->left)
		prefix->rtn += ft_pstv(ft_widthpadding(content, prefix, s));
	return (prefix->rtn);
}
