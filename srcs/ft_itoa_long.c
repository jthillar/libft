/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:54:39 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/18 18:25:22 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

int		ft_intlen_long(long int n)
{
	int		len;

	len = ((n < 0) ? 2 : 1);
	while (((n) > 9) || ((n) < -9))
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa_long(long int n)
{
	unsigned long	m;
	int				i;
	char			*int_ret;

	i = ft_intlen_long(n);
	if (!(int_ret = ft_strnew(i)))
		return (NULL);
	int_ret[i] = '\0';
	i--;
	if (n < 0)
	{
		int_ret[0] = '-';
		m = -1 * (unsigned long)n;
	}
	else
		m = (unsigned long)n;
	while (i >= 0)
	{
		if (i == 0 && n < 0)
			break ;
		int_ret[i] = m % 10 + '0';
		m = m / 10;
		i--;
	}
	return (int_ret);
}
