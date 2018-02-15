/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispaceflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:58:39 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 21:49:55 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_ispaceflag(char *content, intmax_t val, t_prefix **prefix)
{
	t_prefix *cpprefix;

	cpprefix = *prefix;
	if (ft_strchr(content, ' ') && val >= 0 && !cpprefix->sign)
	{
		if (!cpprefix->width)
		{
			ft_putchar(' ');
			cpprefix->rtn++;
		}
		else if (cpprefix->width && cpprefix->zero)
		{
			ft_putchar(' ');
			cpprefix->width--;
			cpprefix->rtn++;
		}
	}
}
