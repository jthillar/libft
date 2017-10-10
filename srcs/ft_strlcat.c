/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:11:04 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/23 18:22:26 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	n_dest_or_n;

	i = 0;
	while (dest[i] && i < n)
		i++;
	n_dest_or_n = i;
	while (src[i - n_dest_or_n] && i < n - 1)
	{
		dest[i] = src[i - n_dest_or_n];
		i++;
	}
	if (n_dest_or_n < n)
		dest[i] = '\0';
	return (n_dest_or_n + ft_strlen(src));
}
