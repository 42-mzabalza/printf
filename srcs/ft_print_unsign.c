/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 22:04:47 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 15:10:34 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_unsign(va_list vlist, char *content, t_prefix *prefix)
{
	uintmax_t	val;

	val = va_arg(vlist, intmax_t);
	if (ft_strchr(content, 'j') || ft_strchr(content, 'U'))
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
	return (ft_print_u(val, content, prefix));
}
