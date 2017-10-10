/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:20:43 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/21 14:11:26 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dst;
	char	*src2;

	i = 0;
	dst = dest;
	src2 = (char *)src;
	while (i < n && (i == 0 || src2[i - 1] != c))
	{
		dst[i] = src2[i];
		i++;
	}
	if (i > 0 && src2[i - 1] == c)
		return (dst + i);
	else
		return (NULL);
}
