/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:19:35 by jthillar          #+#    #+#             */
/*   Updated: 2017/06/15 16:22:08 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *src, int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (i < size)
	{
		str[i] = src[i];
		i++;
	}
	ft_memdel((void **)&src);
	return (str);
}
