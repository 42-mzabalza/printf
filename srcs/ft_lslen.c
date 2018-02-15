/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lslen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:08:16 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 21:51:39 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_lclen(int s)
{
	int len;

	len = 0;
	if (s <= 127)
		len = 1;
	else if (s <= 2047)
		len = 2;
	else if (s <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

int				ft_lsplen(int *str, int j)
{
	int len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (len + ft_lclen(str[i]) > j)
			break ;
		len += ft_lclen(str[i]);
		i++;
	}
	return (len);
}

int				ft_lslen(int *str)
{
	int len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		len += ft_lclen(str[i]);
		i++;
	}
	return (len);
}
