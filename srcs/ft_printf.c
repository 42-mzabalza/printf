/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 02:38:42 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 22:17:13 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_lenformat(char *format)
{
	size_t	len;

	len = 1;
	while (*format)
	{
		if (!ft_strchr(g_notype, *format))
			return (len);
		if (ft_strchr(g_type, *format))
			return (len);
		len++;
		format++;
	}
	return (0);
}

static int		ft_printcenter(char *content, va_list vlist, t_prefix *prefix)
{
	char	specifier;

	specifier = content[ft_pstv(ft_strlen(content) - 1)];
	if (specifier == 'i' || specifier == 'd' || specifier == 'D')
		return (ft_print_integer(vlist, content, prefix, specifier));
	else if (specifier == 's' || specifier == 'S')
		return (ft_print_s(vlist, content, prefix, specifier));
	else if (specifier == 'c' || specifier == 'C')
		return (ft_print_char(vlist, content, prefix, specifier));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_hexa(vlist, content, prefix));
	else if (specifier == 'o' || specifier == 'O')
		return (ft_print_octal(vlist, content, prefix, specifier));
	else if (specifier == 'u' || specifier == 'U')
		return (ft_print_unsign(vlist, content, prefix));
	else if (specifier == 'p')
		return (ft_print_p(vlist, content, prefix));
	else if (specifier == 'b')
		return (ft_print_bina(vlist, content, prefix));
	else if (specifier == '%')
		return (ft_print_prc(content, prefix));
	else
		return (ft_print_extra(content, prefix));
}

static void		ft_else(char c, int *dst)
{
	ft_putchar(c);
	(*dst)++;
}

static int		ft_format_iter(char *format, va_list vlist, int dst)
{
	char		*content;
	int			i;
	int			rst;
	t_prefix	*prefix;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			content = ft_strsub(format, i + 1, ft_lenformat(&format[i + 1]));
			prefix = ft_newprefix(content);
			rst = ft_printcenter(content, vlist, prefix);
			dst += rst;
			i += ft_lenformat(&format[i + 1]);
			free(content);
			free(prefix);
		}
		else
			ft_else(format[i], &dst);
		i++;
	}
	return (dst);
}

int				ft_printf(char *format, ...)
{
	int			dst;
	va_list		vlist;

	dst = 0;
	va_start(vlist, format);
	dst = ft_format_iter(format, vlist, dst);
	va_end(vlist);
	return (dst);
}
