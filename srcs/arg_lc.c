/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_lc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 17:22:02 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 16:36:19 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	addlist_lc(t_str *list, t_print p, wchar_t n, char *str)
{
	if (p.weigth_n > 0)
		add_list(list, ft_strlen(str), str);
	else if (n == 0)
		add_list(list, 1, str);
	else
		add_list(list, ft_strlen(str), str);
	ft_memdel((void**)&str);
}

void		arg_lc(t_print p, wchar_t n, t_str *list)
{
	char	*str;
	char	*fill;
	char	*tmp;

	tmp = NULL;
	fill = NULL;
	if (!(str = ft_strnew(char_len(n))))
		return ;
	str = ft_wchar2char(n, str, char_len(n));
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
	addlist_lc(list, p, n, str);
}
