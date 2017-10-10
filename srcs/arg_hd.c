/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:12:05 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 16:42:07 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*arg_hd_prev_min(size_t size, char *fill, int n, t_print p)
{
	char *tmp;

	tmp = NULL;
	if (!(fill = ft_strnew(size)))
		return (NULL);
	fill = (p.minus == 1) ?
	ft_fill_char(fill, ' ', size) : ft_fill_char(fill, '0', size);
	if (p.minus == 0)
	{
		tmp = ft_strjoin(fill, ft_itoa(-n));
		tmp = ft_left_add_char('-', tmp);
	}
	else
		tmp = ft_strjoin(ft_itoa(n), fill);
	return (tmp);
}

static char	*arg_hd_prev(t_print p, int n, char *str, char *fill)
{
	size_t	size;
	char	*tmp;

	tmp = NULL;
	size = 0;
	size = size_fill(p, size, n);
	if (!(fill = ft_strnew(size)))
		return (NULL);
	if (n >= 0)
	{
		size = (p.plus) ? size - 1 : size;
		if (p.prec < ft_intlen(n) && p.weigth_n > ft_intlen(n))
		{
			fill = (p.minus == 1) ?
			ft_fill_char(fill, ' ', size) : ft_fill_char(fill, '0', size);
		}
		tmp = (p.minus == 1) ? ft_strjoin(str, fill) : ft_strjoin(fill, str);
	}
	else
		tmp = arg_hd_prev_min(size, fill, n, p);
	fill_by_left(tmp, p, '0');
	return (tmp_to_str(tmp, str, fill));
}

static char	*arg_hd_prev2(t_print p, char *str, char *fill, int n)
{
	char *tmp;

	if (!(fill = ft_strnew(p.weigth_n - ft_strlen(str))))
		return (NULL);
	if (p.plus == 1 && n >= 0 && ft_strchr(str, '+') == 0)
		str = ft_left_add_char('+', str);
	fill = ft_fill_char(fill, ' ', p.weigth_n - ft_strlen(str));
	tmp = (p.minus == 1) ? ft_strjoin(str, fill) : ft_strjoin(fill, str);
	return (tmp_to_str(tmp, str, fill));
}

void		arg_hd(t_print p, int n, t_str *list)
{
	char	*str;
	char	*fill;

	fill = NULL;
	str = ft_itoa(n);
	if (n == 0 && p.point == 1 && p.prec == 0)
		str[0] = '\0';
	if ((p.point == 1 && p.prec > ft_intlen(n)) ||
	(p.weigth_zero == 1 && p.prec < p.weigth_n))
	{
		str = arg_hd_prev(p, n, str, fill);
		if (p.plus == 1 && n >= 0)
			str = ft_left_add_char('+', str);
		if (p.prec > p.weigth_n)
		{
			add_list_del_str(list, str);
			return ;
		}
	}
	if ((p.weigth_n > p.prec) || (p.weigth_n > ft_intlen(n)))
		str = arg_hd_prev2(p, str, fill, n);
	if (p.plus == 1 && n >= 0 && ft_strchr(str, '+') == 0)
		str = ft_left_add_char('+', str);
	str = space_d(str, p, n);
	add_list_del_str(list, str);
}
