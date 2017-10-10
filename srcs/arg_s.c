/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:12:22 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/19 13:50:33 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mv_str(char *str, char *src, char *tmp, t_print parse)
{
	if (parse.minus == 0)
	{
		tmp = ft_strjoin(str, src);
		ft_memdel((void**)&src);
	}
	if (parse.minus == 1)
	{
		tmp = ft_strjoin(src, str);
		ft_memdel((void**)&src);
	}
	ft_memdel((void**)&str);
	return (tmp);
}

void	arg_s(t_print parse, char *src, t_str *list)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	if (src == NULL)
		src = ft_strdup("(null)");
	else
		src = ft_strdup(src);
	if (parse.point == 1 && parse.prec < ft_strlen(src))
		src = ft_strcut(src, parse.prec);
	if (parse.weigth_n > ft_strlen(src))
	{
		if (!(str = ft_strnew(parse.weigth_n - ft_strlen(src))))
			return ;
		if (parse.weigth_zero == 1 && parse.minus == 0)
			str = ft_fill_char(str, '0', parse.weigth_n - ft_strlen(src));
		else
			str = ft_fill_char(str, ' ', parse.weigth_n - ft_strlen(src));
		tmp = mv_str(str, src, tmp, parse);
		src = ft_strdup(tmp);
		ft_memdel((void**)&tmp);
	}
	add_list(list, ft_strlen(src), src);
	ft_memdel((void**)&src);
}
