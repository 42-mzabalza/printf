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

static int	ft_widthpadding(char *content, t_prefix *prefix)
{
	int w;

	w = prefix->width - 1;
	while (w-- > 0)
		if (prefix->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
	if (ft_strchr(content, 'l'))
		return (-2);
	return (0);
}

int			ft_print_char(va_list v, char *content, t_prefix *prefix, char s)
{
	prefix->rtn = ft_pstv(prefix->width - 1);
	if (!prefix->left)
		prefix->rtn += ft_pstv(ft_widthpadding(content, prefix));
	if (ft_strchr(content, 'l') || s == 'C')
		return (ft_print_lc(v));
	else
		ft_print_c(v);
	if (prefix->left)
		prefix->rtn += ft_pstv(ft_widthpadding(content, prefix));
	prefix->rtn++;
	return (prefix->rtn);
}
