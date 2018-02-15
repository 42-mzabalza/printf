/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:30:26 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 14:15:24 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_hexa(va_list vlist, char *content, t_prefix *prefix)
{
	uintmax_t val;

	val = va_arg(vlist, intmax_t);
	if (ft_strchr(content, 'j'))
		val = (uintmax_t)val;
	else if (ft_strchr(content, 'z'))
		val = (size_t)val;
	else if (ft_strstr(content, "ll"))
		val = (unsigned long long)val;
	else if (ft_strchr(content, 'l'))
		val = (unsigned long)val;
	else if (ft_strstr(content, "hh"))
		val = (unsigned char)val;
	else if (ft_strchr(content, 'h'))
		val = (unsigned short)val;
	else
		val = (unsigned int)val;
	return (ft_print_x(val, content, prefix));
}
