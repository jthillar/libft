/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:52:48 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/21 11:19:38 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *in, const char *look, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (in[i])
	{
		while (in[i + j] == look[j])
		{
			if (i + j + 1 > len)
				return (NULL);
			if (look[j + 1] == '\0')
				return ((char*)&in[i]);
			j++;
		}
		j = 0;
		i++;
	}
	if (*look == '\0')
		return ((char*)in);
	return (NULL);
}
