/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 00:08:02 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 22:00:08 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_prc(char *content, t_prefix *prefix)
{
	prefix->width = ft_pstv(prefix->width - 1);
	if (!prefix->left)
		prefix->rtn += ft_strwidthpadding(prefix, content);
	ft_putchar('%');
	if (prefix->left)
		prefix->rtn += ft_strwidthpadding(prefix, content);
	prefix->rtn++;
	return (prefix->rtn);
}
