/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonct_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:04:06 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 16:23:20 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_left_add_char(char c, char *src)
{
	char	*tmp;
	int		i;
	size_t	j;

	i = 0;
	j = 1;
	if (!(tmp = ft_strnew(ft_strlen(src) + 1)))
		return (NULL);
	tmp[0] = c;
	while (j < ft_strlen(src) + 1)
	{
		tmp[j] = src[i];
		j++;
		i++;
	}
	if (src)
		ft_memdel((void**)&src);
	src = ft_strdup(tmp);
	ft_memdel((void**)&tmp);
	return (src);
}

char	*ft_strup(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

char	*tmp_to_str(char *tmp, char *str, char *fill)
{
	if (str)
		ft_memdel((void**)&str);
	if (fill)
		ft_memdel((void**)&fill);
	str = ft_strdup(tmp);
	if (tmp)
		ft_memdel((void**)&tmp);
	return (str);
}

char	*fill_by_left(char *tmp, t_print p, char c)
{
	size_t i;
	size_t j;
	size_t size_tmp;

	size_tmp = ft_strlen(tmp);
	j = 0;
	if (p.prec > size_tmp)
	{
		i = p.prec - size_tmp;
		while (j < i)
		{
			tmp = ft_left_add_char(c, tmp);
			j++;
		}
	}
	return (tmp);
}
