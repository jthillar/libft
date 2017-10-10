/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 18:59:56 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 15:28:59 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*mv_lstr(char *str, char *src, char *tmp, t_print parse)
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

void			arg_ls(t_print parse, wchar_t *src, t_str *list)
{
	char	*str;
	char	*str2;
	char	*tmp;

	tmp = NULL;
	if (src == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup_wchar(src, parse);
	if (parse.weigth_n > ft_strlen(str))
	{
		if (!(str2 = ft_strnew(parse.weigth_n - ft_strlen(str))))
			return ;
		if (parse.weigth_zero == 1 && parse.minus == 0)
			str2 = ft_fill_char(str2, '0', parse.weigth_n - ft_strlen(str));
		else
			str2 = ft_fill_char(str2, ' ', parse.weigth_n - ft_strlen(str));
		tmp = mv_lstr(str2, str, tmp, parse);
		str = ft_strdup(tmp);
		ft_memdel((void**)&tmp);
	}
	add_list(list, ft_strlen(str), str);
	ft_memdel((void**)&str);
}
