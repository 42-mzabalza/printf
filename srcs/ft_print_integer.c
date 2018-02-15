/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:30:26 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 21:56:46 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_integer(va_list v, char *content, t_prefix *prefix, char s)
{
	intmax_t	val;

	val = va_arg(v, intmax_t);
	if (ft_strchr(content, 'j'))
		val = (intmax_t)val;
	else if (ft_strchr(content, 'z'))
		val = (size_t)val;
	else if (ft_strstr(content, "ll"))
		val = (long long)val;
	else if (ft_strchr(content, 'l') || s == 'D')
		val = (long)val;
	else if (ft_strstr(content, "hh"))
		val = (signed char)val;
	else if (ft_strchr(content, 'h'))
		val = (short)val;
	else
		val = (int)val;
	return (ft_print_ii(val, content, prefix));
}
