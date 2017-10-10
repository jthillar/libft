/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hhu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:08:54 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 16:36:49 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*arg_hhu_prev(t_print p, unsigned int n, char *str, char *fill)
{
	int		size;
	char	*tmp;

	if (p.point == 1)
		size = p.prec - ft_strlen(ft_itoabase(n, 10));
	else
		size = p.weigth_n - ft_strlen(ft_itoabase(n, 10));
	if (!(fill = ft_strnew(size)))
		return (NULL);
	if (p.minus == 1 && p.prec == 0 && p.prec < p.weigth_n)
		fill = ft_fill_char(fill, ' ', size);
	else
		fill = ft_fill_char(fill, '0', size);
	if (p.minus == 1 && p.prec == 0 && p.prec < p.weigth_n)
		tmp = ft_strjoin(str, fill);
	else
		tmp = ft_strjoin(fill, str);
	return (tmp_to_str(tmp, str, fill));
}

static char	*arg_hhu_prev2(t_print p, char *str, char *fill, unsigned int n)
{
	char *tmp;

	if (!(fill = ft_strnew(p.weigth_n - ft_strlen(str))))
		return (NULL);
	if (p.htag == 1 && n != 0 && str[0] != '0')
		str = ft_left_add_char('0', str);
	fill = ft_fill_char(fill, ' ', p.weigth_n - ft_strlen(str));
	if (p.minus == 1)
		tmp = ft_strjoin(str, fill);
	else
		tmp = ft_strjoin(fill, str);
	return (tmp_to_str(tmp, str, fill));
}

static int	all_zero_hhu(t_print p, t_str *list, unsigned int n)
{
	if (p.prec == 0 && p.point == 1 && p.weigth_n == 0 && n == 0 && p.htag == 0)
	{
		add_list(list, 0, "");
		return (0);
	}
	return (1);
}

void		arg_hhu(t_print p, unsigned char n, t_str *list)
{
	char	*str;
	char	*fill;

	fill = NULL;
	if (all_zero_hhu(p, list, n) == 0)
		return ;
	str = ft_itoabase(n, 10);
	if (n == 0 && p.point == 1 && p.prec == 0 && p.htag == 0)
		str[0] = '\0';
	if ((p.point == 1 && p.prec > ft_strlen(str)) ||
	(p.weigth_zero == 1 && p.prec < p.weigth_n))
	{
		str = arg_hhu_prev(p, n, str, fill);
		if (p.prec > p.weigth_n)
		{
			add_list_del_str(list, str);
			return ;
		}
	}
	if ((p.weigth_n > p.prec) && (p.weigth_n > ft_strlen(ft_itoabase(n, 10))))
		str = arg_hhu_prev2(p, str, fill, n);
	add_list_del_str(list, str);
}
