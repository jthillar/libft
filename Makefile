# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 11:54:39 by jthillar          #+#    #+#              #
#    Updated: 2017/09/11 15:08:40 by jthillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strncmp.c \
	srcs/ft_strlen.c srcs/ft_swap.c srcs/ft_strcpy.c srcs/ft_strncpy.c \
	srcs/ft_strdup.c srcs/ft_strcat.c srcs/ft_strncat.c srcs/ft_atoi.c \
	srcs/ft_strstr.c srcs/ft_strnstr.c srcs/ft_strchr.c srcs/ft_strrchr.c \
	srcs/ft_isalpha.c srcs/ft_isdigit.c srcs/ft_isalnum.c srcs/ft_isascii.c \
	srcs/ft_isprint.c srcs/ft_toupper.c srcs/ft_tolower.c srcs/ft_memset.c \
	srcs/ft_bzero.c srcs/ft_memcpy.c srcs/ft_memccpy.c srcs/ft_memmove.c \
	srcs/ft_memchr.c srcs/ft_memcmp.c srcs/ft_strlcat.c srcs/ft_putendl.c \
	srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c srcs/ft_putendl_fd.c \
	srcs/ft_putnbr.c srcs/ft_putnbr_fd.c srcs/ft_memalloc.c srcs/ft_memdel.c \
	srcs/ft_strnew.c srcs/ft_strdel.c srcs/ft_strclr.c srcs/ft_striter.c \
	srcs/ft_striteri.c srcs/ft_strmap.c srcs/ft_strmapi.c srcs/ft_strequ.c \
	srcs/ft_strnequ.c srcs/ft_strsub.c srcs/ft_strjoin.c srcs/ft_strtrim.c \
	srcs/ft_strsplit.c srcs/ft_itoa.c srcs/ft_lstnew.c srcs/ft_lstdelone.c \
	srcs/ft_lstdel.c srcs/ft_lstadd.c srcs/ft_lstiter.c srcs/ft_lstmap.c \
	srcs/ft_fill_char.c srcs/ft_strcut.c srcs/ft_itoa_long.c \
	srcs/ft_itoabase.c srcs/ft_itoabaselong.c \
	srcs/ft_printf.c srcs/fill_parse.c srcs/syntax_parse.c srcs/ft_call_arg.c \
	srcs/fill_list.c srcs/arg_s.c srcs/arg_d.c srcs/arg_ld.c srcs/arg_x.c \
	srcs/arg_o.c srcs/arg_u.c srcs/arg_lx.c srcs/arg_lo.c srcs/arg_lu.c \
	srcs/ft_fonct_count.c srcs/ft_fonct_str.c srcs/arg_percent.c srcs/arg_p.c \
	srcs/arg_hd.c srcs/arg_c.c srcs/arg_lc.c srcs/arg_hhu.c srcs/arg_hu.c \
	srcs/arg_ho.c srcs/arg_hho.c srcs/arg_hx.c srcs/arg_hhx.c srcs/zero_arg.c \
	srcs/arg_ls.c srcs/wchar_funct.c srcs/arg_b.c srcs/arg_d_fonct.c \
	srcs/arg_ls_p_x_fonct.c srcs/get_next_line.c

OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strncmp.o ft_strlen.o ft_swap.o \
	  ft_strcpy.o ft_strncpy.o ft_strdup.o ft_strcat.o ft_strncat.o ft_atoi.o \
	  ft_strstr.o ft_strnstr.o ft_strchr.o ft_strrchr.o ft_isalpha.o \
	  ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o \
	  ft_tolower.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o \
	  ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlcat.o ft_putendl.o \
	  ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o\
	  ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o \
	  ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o \
	  ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
	  ft_itoa.o \
	  ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o \
	  ft_lstmap.o ft_fill_char.o ft_strcut.o ft_itoa_long.o ft_itoabase.o \
	  ft_itoabaselong.o \
	  ft_printf.o fill_parse.o syntax_parse.o ft_call_arg.o \
	  fill_list.o arg_s.o arg_d.o arg_ld.o arg_x.o arg_o.o arg_u.o \
	  arg_lx.o arg_lo.o arg_lu.o ft_fonct_count.o ft_fonct_str.o \
	  arg_percent.o arg_p.o arg_hd.o arg_c.o arg_lc.o arg_hhu.o \
	  arg_hu.o arg_ho.o arg_hho.o arg_hx.o arg_hhx.o zero_arg.o \
	  arg_ls.o wchar_funct.o arg_b.o arg_d_fonct.o arg_ls_p_x_fonct.o \
	  get_next_line.o

INC = -I includes/

NAME = libft.a

all: $(NAME)

$(NAME):
	@gcc -c -g $(SRC) -Wall -Werror -Wextra $(INC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
