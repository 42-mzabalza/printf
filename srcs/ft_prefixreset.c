/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefixreset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:04:06 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 13:41:29 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prefix	*ft_prefixreset(t_prefix *prefix)
{
	prefix->width = 0;
	prefix->precision = 0;
	prefix->sign = 0;
	prefix->left = 0;
	prefix->zero = 0;
	prefix->rtn = 0;
	return (prefix);
}
