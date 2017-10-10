/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:01:41 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/18 18:52:15 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_wchar(wchar_t n, int base)
{
	int len;

	len = 1;
	while (n > base - 1)
	{
		len++;
		n = n / base;
	}
	return (len);
}

int		char_len(wchar_t n)
{
	int len;

	len = len_wchar(n, 2);
	if (len > 16)
		return (4);
	else if (len > 11)
		return (3);
	else if (len > 7)
		return (2);
	else
		return (1);
}

char	*ft_wchar2char(wchar_t n, char *str, int len)
{
	int i;

	i = 1;
	if (len == 1)
		str[0] = n;
	else
	{
		while (i < len)
		{
			str[len - i] = (n & 0x3F);
			str[len - i] = 0x80 + str[len - i];
			n = n >> 6;
			i++;
		}
		str[0] = (0xF0 << (4 - len) | n);
	}
	return (str);
}
