/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:22:49 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/19 13:10:19 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *mem;

	mem = (char*)malloc(sizeof(char) * (size + 1));
	if (mem != NULL)
		ft_bzero(mem, size + 1);
	else
		mem = NULL;
	return (mem);
}
