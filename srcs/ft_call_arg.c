/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:08:05 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/18 18:28:56 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_arg_x(t_print parse, va_list *ap, t_str *list)
{
	if ((parse.c == 'x' || parse.c == 'X') && parse.l == 0 && parse.j == 0
	&& parse.h == 0 && parse.z == 0)
		arg_x(parse, va_arg(*ap, unsigned int), list);
	if (((parse.c == 'x' || parse.c == 'X') && parse.h == 1))
		arg_hx(parse, (short)va_arg(*ap, unsigned int), list);
	if (((parse.c == 'x' || parse.c == 'X') && parse.h == 2))
		arg_hhx(parse, (char)va_arg(*ap, unsigned int), list);
	if ((parse.c == 'x' || parse.c == 'X') && parse.l != 0)
		arg_lx(parse, va_arg(*ap, unsigned long), list);
	if (((parse.c == 'x' || parse.c == 'X') && parse.j != 0))
		arg_lx(parse, (uintmax_t)va_arg(*ap, unsigned long), list);
	if ((parse.c == 'x' || parse.c == 'X') && parse.z != 0)
		arg_lx(parse, (ssize_t)va_arg(*ap, unsigned long), list);
}

void	ft_call_arg_o(t_print parse, va_list *ap, t_str *list)
{
	if (parse.c == 'o' && parse.l == 0 && parse.j == 0 && parse.h == 0
	&& parse.z == 0)
		arg_o(parse, va_arg(*ap, unsigned int), list);
	if ((parse.c == 'o' && parse.l != 0) || parse.c == 'O')
		arg_lo(parse, va_arg(*ap, unsigned long), list);
	if (parse.c == 'o' && parse.h == 1)
		arg_ho(parse, (short)va_arg(*ap, unsigned int), list);
	if (parse.c == 'o' && parse.h == 2)
		arg_hho(parse, (char)va_arg(*ap, unsigned int), list);
	if (parse.c == 'o' && parse.j != 0)
		arg_lo(parse, (uintmax_t)va_arg(*ap, unsigned long), list);
	if (parse.c == 'o' && parse.z != 0)
		arg_lo(parse, (ssize_t)va_arg(*ap, unsigned long), list);
}

void	ft_call_arg_u(t_print parse, va_list *ap, t_str *list)
{
	if (parse.c == 'u' && parse.l == 0 && parse.j == 0 && parse.h == 0
	&& parse.z == 0)
		arg_u(parse, va_arg(*ap, unsigned int), list);
	if ((parse.c == 'u' && parse.l != 0) || parse.c == 'U')
		arg_lu(parse, va_arg(*ap, unsigned long), list);
	if (parse.c == 'u' && parse.h == 1)
		arg_hu(parse, (short)va_arg(*ap, unsigned int), list);
	if (parse.c == 'u' && parse.h == 2)
		arg_hhu(parse, (char)va_arg(*ap, unsigned int), list);
	if (parse.c == 'u' && parse.j != 0)
		arg_lu(parse, (uintmax_t)va_arg(*ap, unsigned long), list);
	if (parse.c == 'u' && parse.z != 0)
		arg_lu(parse, (ssize_t)va_arg(*ap, unsigned long), list);
}

void	ft_call_arg_else(t_print parse, va_list *ap, t_str *list)
{
	if (parse.c == 'p')
		arg_p(parse, va_arg(*ap, unsigned long long), list);
	if (parse.c == '%')
		arg_percent(parse, list);
	if (parse.c == 's' && parse.l == 0)
		arg_s(parse, va_arg(*ap, char *), list);
	if (parse.c == 'S' || (parse.c == 's' && parse.l == 1))
		arg_ls(parse, va_arg(*ap, wchar_t *), list);
	if (parse.c == 'c' && parse.l == 0)
		arg_c(parse, (char)va_arg(*ap, int), list);
	if ((parse.c == 'c' && parse.l == 1) || parse.c == 'C')
		arg_lc(parse, (wchar_t)va_arg(*ap, int), list);
	if (parse.c == 'b')
		arg_b(va_arg(*ap, unsigned int), list);
	if (parse.c != 's' && parse.c != 'S' && parse.c != 'p'
	&& parse.c != 'd' && parse.c != 'D' && parse.c != 'i'
	&& parse.c != 'o' && parse.c != 'O' && parse.c != 'u'
	&& parse.c != 'U' && parse.c != 'x' && parse.c != 'X'
	&& parse.c != 'c' && parse.c != 'C' && parse.c != '%' && parse.c != 'b')
		zero_arg(parse, list);
}

void	ft_call_arg(t_print parse, va_list *ap, t_str *list)
{
	if ((parse.c == 'd' || parse.c == 'i') && parse.l == 0
	&& parse.h == 0 && parse.j == 0 && parse.z == 0)
		arg_d(parse, va_arg(*ap, int), list);
	if (((parse.c == 'd' || parse.c == 'i') && parse.l != 0) || parse.c == 'D')
		arg_ld(parse, va_arg(*ap, long int), list);
	if (((parse.c == 'd' || parse.c == 'i') && parse.h == 1))
		arg_hd(parse, (short)va_arg(*ap, int), list);
	if (((parse.c == 'd' || parse.c == 'i') && parse.h == 2))
		arg_hd(parse, (char)va_arg(*ap, int), list);
	if (((parse.c == 'd' || parse.c == 'i') && parse.j != 0))
		arg_ld(parse, (intmax_t)va_arg(*ap, long int), list);
	if (((parse.c == 'd' || parse.c == 'i') && parse.z != 0))
		arg_ld(parse, (ssize_t)va_arg(*ap, long int), list);
	ft_call_arg_x(parse, ap, list);
	ft_call_arg_o(parse, ap, list);
	ft_call_arg_u(parse, ap, list);
	ft_call_arg_else(parse, ap, list);
}
