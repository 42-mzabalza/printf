/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 21:58:29 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 22:33:08 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print_unicode(int val)
{
	int		bytes;
	char	*dst;
	long	bin;
	int		i;
	int		rtn;

	bytes = 11110;
	if (val <= 127)
		return (write(1, &val, 1));
	else if (val <= 2047)
		bytes = 110;
	else if (val <= 65535)
		bytes = 1110;
	bin = ft_dectobin(val);
	dst = (char *)malloc(sizeof(char) * ft_ndigits(bytes) - 1);
	i = ft_ndigits(bytes) - 1;
	while (i-- > 1)
		dst[i] = ft_bintodec(ft_utf8(&bin, i));
	dst[0] = ft_bintodec((bytes * (ft_pow(10, 8 - ft_ndigits(bytes)))) + bin);
	rtn = write(1, dst, ft_ndigits(bytes) - 1);
	free(dst);
	return (rtn);
}

int				ft_newstrls(int *str, t_prefix *prefix, char *content)
{
	int i;
	int p;
	int	j;

	p = prefix->precision;
	i = 0;
	j = 0;
	while (str[i])
	{
		j += ft_lclen(str[i]);
		if (ft_strchr(content, '.') && j > p)
			break ;
		prefix->rtn += ft_print_unicode(str[i]);
		i++;
	}
	return (prefix->rtn);
}

int				ft_print_ls(va_list vlist, char *content, t_prefix *prefix)
{
	int		*str;
	char	*content2;
	int		len;

	content2 = content;
	str = va_arg(vlist, int *);
	if (str == NULL && !ft_strchr(content, '.'))
	{
		ft_putstr("(null)");
		return (6);
	}
	if (!ft_strchr(content, '.'))
		len = ft_lslen(str);
	else
		len = ft_lsplen(str, prefix->precision);
	prefix->width = ft_pstv(prefix->width - len);
	if (!ft_strchr(content, '-'))
		prefix->rtn += ft_strwidthpadding(prefix, content);
	prefix->rtn = ft_newstrls(str, prefix, content);
	if (ft_strchr(content, '-'))
		prefix->rtn += ft_strwidthpadding(prefix, content);
	return (prefix->rtn);
}
