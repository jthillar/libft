/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:34:21 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 16:29:09 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_list_c(t_print p, char *str, t_str *list)
{
	if (p.weigth_n > 0)
		add_list(list, p.weigth_n, str);
	else
		add_list(list, 1, str);
	ft_memdel((void**)&str);
}

void		arg_c(t_print p, char n, t_str *list)
{
	char	*str;
	char	*fill;
	char	*tmp;

	tmp = NULL;
	fill = NULL;
	if (!(str = ft_strnew(0)))
		return ;
	str[0] = n;
	if (p.weigth_n > 0)
	{
		if (!(fill = ft_strnew(p.weigth_n - 1)))
			return ;
		if (p.minus == 1)
			ft_fill_char(fill, ' ', p.weigth_n - 1);
		else
		{
			fill = (p.weigth_zero == 1) ?
			ft_fill_char(fill, '0', p.weigth_n - 1) :
			ft_fill_char(fill, ' ', p.weigth_n - 1);
		}
		tmp = (p.minus == 1) ? ft_strjoin(str, fill) : ft_strjoin(fill, str);
		str = tmp_to_str(tmp, str, fill);
	}
	add_list_c(p, str, list);
}
