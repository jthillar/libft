/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:57:01 by jthillar          #+#    #+#             */
/*   Updated: 2017/08/21 11:26:01 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <wchar.h>
# include <limits.h>
# include "libft.h"

typedef	struct		s_print
{
	int		minus;
	int		plus;
	int		space;
	int		htag;
	int		weigth_zero;
	size_t	weigth_n;
	int		star_1;
	int		point;
	size_t	prec;
	int		star_2;
	int		h;
	int		l;
	int		j;
	int		z;
	char	c;
}					t_print;

typedef	struct		s_str
{
	char			*str;
	int				ret;
	struct s_str	*next;
}					t_str;

int					ft_printf(char *fmt, ...);
void				ft_parse(char **fmt, va_list *ap, t_str *list);
t_str				*init_list();
int					add_list(t_str	*list, int size, char *fmt);
t_str				*list_remove_first(t_str *list);
void				ft_free_list(t_str *list);
void				add_list_del_str(t_str *list, char *str);
t_print				fill_parse(char **fmt);
void				flag_parse(t_print *parse, char **fmt);
void				weigth_parse(t_print *parse, char **fmt);
void				precision_parse(t_print *parse, char **fmt);
void				length_parse(t_print *parse, char **fmt);
void				type_parse(t_print *parse, char **fmt);
void				ft_call_arg(t_print parse, va_list *ap, t_str *list);
size_t				ft_intlen(int n);
char				*ft_left_add_char(char c, char *src);
char				*ft_strup(char *str);
char				*fill_by_left(char *tmp, t_print p, char c);
char				*tmp_to_str(char *tmp, char *str, char *fill);
int					len_wchar(wchar_t n, int base);
int					char_len(wchar_t n);
char				*ft_wchar2char(wchar_t n, char *str, int len);
void				arg_s(t_print parse, char *src, t_str *list);
void				arg_ls(t_print parse, wchar_t *src, t_str *list);
size_t				len_str_wchar(wchar_t *src);
char				*ft_strdup_wchar(wchar_t *src, t_print p);
void				arg_d(t_print parse, int n, t_str *list);
void				arg_hd(t_print parse, int n, t_str *list);
void				arg_ld(t_print parse, long int n, t_str *list);
char				*space_d(char *str, t_print p, int n);
size_t				size_fill(t_print p, size_t size, int n);
void				arg_x(t_print parse, unsigned int n, t_str *list);
void				arg_lx(t_print parse, unsigned long n, t_str *list);
void				arg_hx(t_print p, unsigned short n, t_str *list);
void				arg_hhx(t_print p, unsigned char n, t_str *list);
void				htag_addlist(t_print p, char *str, unsigned int n,
	t_str *list);
void				arg_o(t_print parse, unsigned int n, t_str *list);
void				arg_lo(t_print parse, unsigned long n, t_str *list);
void				arg_ho(t_print p, unsigned short n, t_str *list);
void				arg_hho(t_print p, unsigned char n, t_str *list);
void				arg_u(t_print parse, unsigned int n, t_str *list);
void				arg_lu(t_print parse, unsigned long n, t_str *list);
void				arg_hu(t_print p, unsigned short n, t_str *list);
void				arg_hhu(t_print p, unsigned char n, t_str *list);
void				arg_percent(t_print p, t_str *list);
void				arg_p(t_print p, unsigned long n, t_str *list);
void				htag_p_addlist(char *str, t_str *list);
void				arg_c(t_print parse, char n, t_str *list);
void				arg_lc(t_print parse, wchar_t n, t_str *list);
void				arg_b(unsigned int n, t_str *list);
void				zero_arg(t_print p, t_str *list);
int					only_one_percent(char *fmt, t_str *list);
#endif
