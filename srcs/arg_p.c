/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:44:48 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 16:39:16 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*arg_p_prev(t_print p, unsigned long n, char *str, char *fill)
{
	int		size;
	char	*tmp;

	if (p.point == 1)
		size = p.prec - ft_strlen(ft_itoabaselong(n, 16)) + 2;
	else
		size = p.weigth_n - ft_strlen(ft_itoabaselong(n, 16));
	if (!(fill = ft_strnew(size)))
		return (NULL);
	if (p.minus == 1 && p.prec == 0 && p.prec < p.weigth_n)
		fill = ft_fill_char(fill, ' ', size);
	else
		fill = ft_fill_char(fill, '0', size - 2);
	if (p.minus == 1 && p.prec == 0 && p.prec < p.weigth_n
	&& p.weigth_n > ft_strlen(ft_itoabaselong(n, 16)))
		tmp = ft_strjoin(str, fill);
	else
	{
		tmp = ft_strjoin(fill, str);
		tmp = ft_left_add_char('x', tmp);
		tmp = ft_left_add_char('0', tmp);
	}
	return (tmp_to_str(tmp, str, fill));
}

static char	*arg_p_prev2(t_print p, char *str, char *fill)
{
	char *tmp;

	if (!(fill = ft_strnew(p.weigth_n - ft_strlen(str))))
		return (NULL);
	if (!(ft_strchr(str, 'x')))
	{
		str = ft_left_add_char('x', str);
		str = ft_left_add_char('0', str);
	}
	fill = ft_fill_char(fill, ' ', p.weigth_n - ft_strlen(str));
	if (p.minus == 1)
		tmp = ft_strjoin(str, fill);
	else
		tmp = ft_strjoin(fill, str);
	return (tmp_to_str(tmp, str, fill));
}

static int	all_zero_p(t_print p, t_str *list, unsigned long n)
{
	if (p.prec == 0 && p.point == 1 && p.weigth_n == 0 && n == 0 && p.htag == 0)
	{
		add_list(list, 2, "0x");
		return (0);
	}
	return (1);
}

void		arg_p(t_print p, unsigned long n, t_str *list)
{
	char	*str;
	char	*fill;

	fill = NULL;
	if (all_zero_p(p, list, n) == 0)
		return ;
	str = ft_itoabaselong(n, 16);
	if (n == 0 && p.point == 1 && p.prec == 0)
		str[0] = '\0';
	if ((p.point == 1 && p.prec > ft_strlen(str)) ||
	(p.weigth_n > ft_strlen(str) && p.weigth_zero == 1 && p.prec < p.weigth_n))
	{
		str = arg_p_prev(p, n, str, fill);
		if (p.prec > p.weigth_n)
		{
			add_list(list, ft_strlen(str), str);
			ft_memdel((void**)&str);
			return ;
		}
	}
	if ((p.weigth_n > p.prec) &&
	(p.weigth_n > ft_strlen(ft_itoabaselong(n, 16))))
		str = arg_p_prev2(p, str, fill);
	htag_p_addlist(str, list);
}
