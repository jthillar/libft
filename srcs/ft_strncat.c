/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:11:04 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/16 16:44:26 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t n_dest;

	i = 0;
	n_dest = ft_strlen(dest);
	while (src[i] && i < n)
	{
		dest[n_dest + i] = (char)src[i];
		i++;
	}
	dest[n_dest + i] = '\0';
	return (dest);
}
