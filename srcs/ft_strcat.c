/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:11:04 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/15 16:34:25 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int n_dest;

	i = 0;
	n_dest = ft_strlen(dest);
	while (src[i])
	{
		dest[n_dest + i] = (char)src[i];
		i++;
	}
	dest[n_dest + i] = '\0';
	return (dest);
}
