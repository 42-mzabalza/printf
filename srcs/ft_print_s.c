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

static int	ft_showstr(char *str, char *content, t_prefix *prefix)
{
	int p;
	int dot;
	int i;

	dot = 0;
	i = 0;
	if (ft_strchr(content, '.'))
		dot = 1;
	p = prefix->precision;
	while (str[i])
	{
		if (dot && !p)
			return (i);
		ft_putchar(str[i]);
		i++;
		p--;
	}
	return (i);
}

static int	ft_showlen(char *str, char *content, t_prefix *prefix)
{
	int p;
	int dot;
	int i;

	dot = 0;
	i = 0;
	if (ft_strchr(content, '.'))
		dot = 1;
	p = prefix->precision;
	while (str[i])
	{
		if (dot && !p)
			return (i);
		i++;
		p--;
	}
	return (i);
}

int			ft_print_s(va_list v, char *content, t_prefix *p, char specifier)
{
	char	*str;

	if (ft_strchr(content, 'l') || specifier == 'S')
		return (ft_print_ls(v, content, p));
	str = va_arg(v, char *);
	if (str == NULL)
		str = "(null)";
	p->width = ft_pstv(p->width - ft_showlen(str, content, p));
	p->rtn += p->width;
	if (!ft_strchr(content, '-'))
		ft_strwidthpadding(p, content);
	p->rtn += ft_showstr(str, content, p);
	if (ft_strchr(content, '-'))
		ft_strwidthpadding(p, content);
	return (p->rtn);
}
