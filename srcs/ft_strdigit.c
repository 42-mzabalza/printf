/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:26:47 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 15:12:19 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strdigit(char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (ft_isdigit(content[i]) && content[i] != '0')
			return (i);
		if (content[i] == '.')
			return (0);
		i++;
	}
	return (0);
}
