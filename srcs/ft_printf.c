/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:27:41 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 15:46:36 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	ft_sum_n(t_str *list)
{
	int		n;
	t_str	*tmp;

	n = 0;
	tmp = list;
	while (tmp)
	{
		n += tmp->ret;
		tmp = tmp->next;
	}
	return (n);
}

static char	*ft_strcat_p(char *dest, char *src, int end, int begin)
{
	int	length;
	int i;

	length = end + begin;
	i = 0;
	while (begin + i < length)
	{
		dest[begin + i] = (char)src[i];
		i++;
	}
	dest[begin + i] = '\0';
	return (dest);
}

static int	ft_printlist(t_str *list)
{
	int		n;
	t_str	*tmp;
	char	*print;

	n = ft_sum_n(list);
	if (!(print = ft_strnew(n)))
		return (-1);
	tmp = list;
	n = 0;
	while (tmp)
	{
		print = ft_strcat_p(print, tmp->str, tmp->ret, n);
		n += tmp->ret;
		tmp = tmp->next;
	}
	write(1, print, n);
	ft_memdel((void **)&print);
	return (n);
}

void		ft_parse(char **fmt, va_list *ap, t_str *list)
{
	int	i;

	i = 0;
	if (only_one_percent(*fmt, list) == 0)
		return ;
	if (!(ft_strchr(*fmt, '%')))
	{
		add_list(list, ft_strlen(*fmt), *fmt);
		return ;
	}
	if ((*fmt)[i] && (*fmt)[i] != '%')
	{
		while ((*fmt)[i] != '%')
			i++;
		add_list(list, i, *fmt);
	}
	if ((*fmt)[i] && (*fmt)[i] == '%')
	{
		*fmt += i + 1;
		ft_call_arg(fill_parse(fmt), ap, list);
		if (ft_strcmp(*fmt, "\0") == 0)
			return ;
	}
	ft_parse(fmt, ap, list);
}

int			ft_printf(char *fmt, ...)
{
	va_list	ap;
	t_str	*list;
	int		n;

	list = NULL;
	list = init_list();
	va_start(ap, fmt);
	ft_parse(&fmt, &ap, list);
	va_end(ap);
	n = ft_printlist(list);
	ft_free_list(list);
	return (n);
}
