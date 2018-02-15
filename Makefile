# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 11:50:39 by mzabalza          #+#    #+#              #
#    Updated: 2018/02/03 16:04:25 by mzabalza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes

PRINTF_DIR = srcs/

LIBFT_DIR = libft/

OBJ_DIR = objects/

PRINTF_SRC = ft_printf.c\
		ft_print_ii.c\
		ft_ispaceflag.c\
		ft_print_integer.c\
		ft_print_hexa.c\
		ft_print_octal.c\
		ft_print_bina.c\
		ft_print_unsign.c\
		ft_print_p.c\
		ft_print_char.c\
		ft_print_c.c\
		ft_print_lc.c\
		ft_lslen.c\
		ft_print_ls.c\
		ft_print_o.c\
		ft_print_u.c\
		ft_print_s.c\
		ft_print_prc.c\
		ft_print_x.c\
		ft_print_b.c\
		ft_strdigit.c\
		ft_iszero.c\
		ft_ndigits.c\
		ft_undigits.c\
		ft_newprefix.c\
		ft_prefixreset.c\
		ft_pstv.c\
		ft_print_extra.c


LIBFT_SRC = ft_strstr.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strdel.c\
		ft_itoa_base.c\
		ft_imaxtoa_base.c\
		ft_uimaxtoa_base.c\
		ft_putmaxint.c\
		ft_putmaxuint.c\
		ft_putlong.c\
		ft_strlen.c\
		ft_strsub.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_pow.c\
		ft_atoi.c\
		ft_abs.c\
		ft_isdigit.c\
		ft_putnbr.c\
		ft_strncmp.c\
		ft_strsub.c

OBJ_PRINTF = $(patsubst %.c, $(OBJ_DIR)%.o, $(PRINTF_SRC))

OBJ_LIBFT = $(patsubst %.c, $(LIBFT_DIR)%.o, $(LIBFT_SRC))

OBJ = $(OBJ_PRINTF) $(OBJ_LIBFT)

all: $(NAME)

$(NAME): $(OBJ_PRINTF) $(OBJ_LIBFT)
			ranlib $(NAME)
		 	
$(OBJ_DIR)%.o: $(PRINTF_DIR)%.c
		 	@gcc $(FLAGS) -Iincludes -c $< 
			@mkdir -p $(OBJ_DIR)
			@mv -f $(@F) $(OBJ_DIR)
			@ar r $(NAME) $@

$(LIBFT_DIR)%.o: $(LIBFT_DIR)%.c
			@$(MAKE) -C $(LIBFT_DIR) $(@F)
			@ar r $(NAME) $@

clean:
			@$(MAKE) -C libft clean
			@/bin/rm -rf $(OBJ_PRINTF) $(OBJ_LIBFT)
			@/bin/rm -rvf $(OBJ_DIR)
			@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
			@$(MAKE) -C libft fclean
		 	@/bin/rm -f $(NAME)
		 	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean
			@make

.PHONY: clean fclean re all
