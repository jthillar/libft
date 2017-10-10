/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:08:11 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/16 18:46:32 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd((char)str[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
