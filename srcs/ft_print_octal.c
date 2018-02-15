/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:34:58 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 21:59:37 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_octal(va_list v, char *content, t_prefix *prefix, char s)
{
	uintmax_t val;

	val = va_arg(v, intmax_t);
	if (ft_strchr(content, 'j'))
		val = (uintmax_t)val;
	else if (ft_strchr(content, 'z'))
		val = (size_t)val;
	else if (ft_strstr(content, "ll"))
		val = (unsigned long long)val;
	else if (ft_strchr(content, 'l') || s == 'O')
		val = (unsigned long)val;
	else if (ft_strstr(content, "hh"))
		val = (unsigned char)val;
	else if (ft_strchr(content, 'h'))
		val = (unsigned short)val;
	else
		val = (unsigned int)val;
	return (ft_print_o(val, content, prefix));
}
