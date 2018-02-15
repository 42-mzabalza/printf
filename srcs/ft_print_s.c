/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:56:02 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 22:07:27 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strwidthpadding(t_prefix *prefix, char *content)
{
	int rtn;
	int w;

	content++;
	rtn = 0;
	w = prefix->width;
	rtn += w;
	while (w-- > 0)
	{
		if (prefix->zero && !prefix->left)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	return (rtn);
}

int			ft_print_s(va_list v, char *content, t_prefix *p, char specifier)
{
	char	*str;

	if (ft_strchr(content, 'l') || specifier == 'S')
		return (ft_print_ls(v, content, p));
	str = va_arg(v, char *);
	if (ft_strchr(content, '.') && str
			&& !(p->precision >= (int)ft_strlen(str)))
		str = ft_strsub(str, 0, p->precision);
	p->precision = ft_pstv(p->precision - ft_strlen(str));
	if (str == NULL && !ft_strchr(content, '.'))
		str = "(null)";
	p->width = ft_pstv(p->width - ft_strlen(str));
	p->rtn += p->width;
	if (!ft_strchr(content, '-'))
		ft_strwidthpadding(p, content);
	ft_putstr(str);
	if (ft_strchr(content, '-'))
		ft_strwidthpadding(p, content);
	p->rtn += ft_strlen(str);
	return (p->rtn);
}
