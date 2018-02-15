/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:07:57 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/08 22:43:44 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

static char		type[] = "pdDioOuUxXcCsSb%\0";
static char		notype[] = " 123456789.%hljz#0-+pdDioOuUxXcCsSb%\0";

typedef struct	s_prefix
{
	int			width;
	int			precision;
	int			sign;
	int			left;
	int			zero;
	int			rtn;
}				t_prefix;

int				ft_printf(char *format, ...);
int				ft_print_ii(intmax_t val, char *content, t_prefix *prefix);
void			ft_ispaceflag(char *content, intmax_t val, t_prefix **prefix);
int				ft_print_integer(va_list v, char *con, t_prefix *pre, char s);
int				ft_print_hexa(va_list vlist, char *content, t_prefix *prefix);
int				ft_print_octal(va_list vl, char *cont, t_prefix *pr, char s);
int				ft_print_bina(va_list vlist, char *content, t_prefix *prefix);
int				ft_print_unsign(va_list vlist, char *content, t_prefix *prefix);
int				ft_print_p(va_list vlist, char *content, t_prefix *prefix);
int				ft_print_s(va_list v, char *cont, t_prefix *prefix, char s);
int				ft_print_char(va_list v, char *cont, t_prefix *pre, char s);
int				ft_print_lc(va_list vlist);
int				ft_utf8(long *bin, int i);
int				ft_bintodec(long bin);
long			ft_dectobin(int nb);
int				ft_print_ls(va_list vlist, char *content, t_prefix *prefix);
int				ft_lslen(int *str);
int				ft_lclen(int s);
int				ft_lsplen(int *str, int j);
int				ft_strwidthpadding(t_prefix *prefix, char *content);
void			ft_print_c(va_list vlist);
int				ft_print_x(intmax_t val, char *content, t_prefix *prefix);
int				ft_print_o(intmax_t val, char *content, t_prefix *prefix);
int				ft_print_b(intmax_t val, char *content, t_prefix *prefix);
int				ft_print_u(uintmax_t val, char *content, t_prefix *prefix);
int				ft_print_prc(char *content, t_prefix *prefix);
int				ft_strdigit(char *content);
int				ft_iszero(char *content);
int				ft_ndigits(intmax_t nb);
int				ft_undigits(uintmax_t nb);
int				ft_pstv(int nb);
int				ft_print_extra(char *content, t_prefix *prefix);
t_prefix		*ft_newprefix(char *content);
t_prefix		*ft_prefixreset(t_prefix *prefix);

#endif
