/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:09:13 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 16:41:26 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_percent(t_print p, t_str *list)
{
	char	*str;
	char	*fill;
	char	*tmp;

	if (!(str = ft_strnew(1)))
		return ;
	str[0] = '%';
	fill = NULL;
	tmp = NULL;
	if (p.weigth_n > 1)
	{
		if (!(fill = ft_strnew(p.weigth_n - 1)))
			return ;
		fill = (p.weigth_zero == 1 && p.minus == 0) ?
		ft_fill_char(fill, '0', p.weigth_n - 1) :
		ft_fill_char(fill, ' ', p.weigth_n - 1);
		tmp = (p.minus == 1) ? ft_strjoin(str, fill) : ft_strjoin(fill, str);
		str = tmp_to_str(tmp, str, fill);
	}
	add_list(list, ft_strlen(str), str);
	ft_memdel((void**)&str);
}
