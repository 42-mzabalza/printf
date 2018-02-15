/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:05:48 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 21:53:01 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_widthpadding(t_prefix *prefix)
{
	int w;

	w = prefix->width;
	while (w-- > 0)
	{
		if (prefix->zero && !prefix->left)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

int				ft_print_extra(char *content, t_prefix *prefix)
{
	prefix->width = ft_pstv(prefix->width - 1);
	prefix->rtn = prefix->width;
	if (!prefix->left)
		ft_widthpadding(prefix);
	ft_putchar(content[ft_pstv(ft_strlen(content) - 1)]);
	if (prefix->left)
		ft_widthpadding(prefix);
	if (content[ft_pstv(ft_strlen(content) - 1)])
		prefix->rtn++;
	return (prefix->rtn);
}
