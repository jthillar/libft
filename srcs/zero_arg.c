/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:39:29 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 15:59:58 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			only_one_percent(char *fmt, t_str *list)
{
	if (ft_strlen(fmt) == 1 && fmt[0] == '%' && fmt[1] == '\0')
	{
		add_list(list, 0, "");
		return (0);
	}
	return (1);
}

static void	z_arg_min(t_print p, char *str, char *tmp, t_str *list)
{
	char	*fill;

	if (!(fill = ft_strnew(p.weigth_n - 1)))
		return ;
	if (p.weigth_zero == 1)
		fill = ft_fill_char(fill, '0', p.weigth_n - 1);
	else
		fill = ft_fill_char(fill, ' ', p.weigth_n - 1);
	tmp = ft_strjoin(fill, str);
	str = tmp_to_str(tmp, str, fill);
	add_list_del_str(list, str);
}

void		zero_arg(t_print p, t_str *list)
{
	char	*fill;
	char	*tmp;
	char	*str;

	tmp = NULL;
	if (!(str = ft_strnew(1)))
		return ;
	str[0] = p.c;
	if (p.minus == 0 && p.weigth_n > 0)
	{
		z_arg_min(p, str, tmp, list);
		return ;
	}
	if (p.minus == 1 && p.weigth_n > 0)
	{
		if (!(fill = ft_strnew(p.weigth_n)))
			return ;
		fill = ft_fill_char(fill, ' ', p.weigth_n);
		fill = ft_left_add_char(p.c, fill);
		add_list(list, p.weigth_n, fill);
		ft_memdel((void**)&fill);
		return ;
	}
	add_list_del_str(list, str);
}
