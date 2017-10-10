/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabaselong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:42:19 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/18 18:26:53 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define HEXA(x) ((x >= 10) ? x - 10 + 'a' : x + '0')

char	*ft_itoabaselong(unsigned long n, int base)
{
	char			*str;
	unsigned long	m;
	int				i;

	m = n;
	i = 1;
	while (m / base != 0)
	{
		i++;
		m = m / base;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i > 0)
	{
		str[i - 1] = HEXA(n % base);
		n = n / base;
		i--;
	}
	return (str);
}
