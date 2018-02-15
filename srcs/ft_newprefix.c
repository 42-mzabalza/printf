/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:32:49 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 14:21:43 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parsezero(char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '0')
			return (i + 1);
		if (ft_isdigit(content[i]) && content[i] != '0')
			return (0);
		i++;
	}
	return (0);
}

static void	ft_parsecontent(char *content, t_prefix *prefix)
{
	prefix->zero = ft_parsezero(content);
	prefix->width = ft_atoi(content + (ft_strdigit(content)));
	if ((ft_strchr(content, '.')))
		prefix->precision = ft_atoi((ft_strchr(content, '.')) + 1);
	if (ft_strchr(content, '+'))
		prefix->sign = 1;
	if (ft_strchr(content, '-'))
		prefix->left = 1;
}

t_prefix	*ft_newprefix(char *content)
{
	t_prefix *prefix;

	if (!(prefix = (t_prefix *)malloc(sizeof(t_prefix))))
		return (NULL);
	prefix = ft_prefixreset(prefix);
	ft_parsecontent(content, prefix);
	return (prefix);
}
