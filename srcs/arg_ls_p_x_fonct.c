/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_ls_p_x_fonct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:15:54 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 15:33:48 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		htag_addlist(t_print p, char *str, unsigned int n, t_str *list)
{
	if (p.htag == 1 && n != 0 && !(ft_strchr(str, 'x')))
	{
		str = ft_left_add_char('x', str);
		str = ft_left_add_char('0', str);
	}
	if (p.c == 'X')
		add_list(list, ft_strlen(str), ft_strup(str));
	else
		add_list(list, ft_strlen(str), str);
	ft_memdel((void**)&str);
}

void		htag_p_addlist(char *str, t_str *list)
{
	if (!(ft_strchr(str, 'x')))
	{
		str = ft_left_add_char('x', str);
		str = ft_left_add_char('0', str);
	}
	add_list(list, ft_strlen(str), str);
	ft_memdel((void**)&str);
}

size_t		len_str_wchar(wchar_t *src)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (src[i])
	{
		len += char_len(src[i]);
		i++;
	}
	return (len);
}

static char	*create_dest_ls(char *dest, t_print p, wchar_t *src)
{
	if (p.point == 1 && p.prec < len_str_wchar(src))
	{
		if (!(dest = ft_strnew(p.prec)))
			return (NULL);
	}
	else
	{
		if (!(dest = ft_strnew(len_str_wchar(src))))
			return (NULL);
	}
	return (dest);
}

char		*ft_strdup_wchar(wchar_t *src, t_print p)
{
	char	*dest;
	char	*tmp;
	size_t	i;
	int		len;

	i = 0;
	dest = NULL;
	dest = create_dest_ls(dest, p, src);
	while (src[i])
	{
		len = char_len(src[i]);
		tmp = NULL;
		if (!(tmp = ft_strnew(len)))
			return (NULL);
		tmp = ft_wchar2char(src[i], tmp, len);
		if (p.point == 1 && ft_strlen(dest) + ft_strlen(tmp) > p.prec)
		{
			ft_memdel((void**)&tmp);
			break ;
		}
		dest = ft_strcat(dest, tmp);
		ft_memdel((void**)&tmp);
		i++;
	}
	return (dest);
}
