/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:20:47 by jthillar          #+#    #+#             */
/*   Updated: 2017/06/15 16:31:07 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill_char(char *str, char a, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = a;
		i++;
	}
	return (str);
}
