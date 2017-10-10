/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:09:11 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/24 11:13:42 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*s2;
	int		i;

	if (s == NULL || *f == NULL)
		return (NULL);
	i = 0;
	s2 = ft_strnew(sizeof(char) * (ft_strlen(s)));
	if (s2 == NULL)
		return (NULL);
	while (s[i])
	{
		s2[i] = f((char)s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
