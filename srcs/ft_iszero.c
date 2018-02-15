/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iszero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:59:07 by mzabalza          #+#    #+#             */
/*   Updated: 2018/01/30 04:03:27 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iszero(char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '0' || content[i] == '.')
			return (i + 1);
		if (ft_isdigit(content[i]) && content[i] != '0')
			return (0);
		i++;
	}
	return (0);
}
