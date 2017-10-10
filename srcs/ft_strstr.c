/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:51:02 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/21 11:04:21 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *in, const char *look)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (in[i])
	{
		while (in[i + j] == look[j])
		{
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
