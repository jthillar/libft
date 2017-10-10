/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_d_fonct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 09:55:54 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 14:02:46 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*space_d(char *str, t_print p, int n)
{
	if ((p.space != 0 && p.point == 1 && n >= 0 && p.weigth_n < ft_intlen(n))
		|| (p.space != 0 && p.point == 0 && p.weigth_n == 0
		&& p.weigth_zero == 0 && p.plus == 0 && n >= 0))
		str = ft_left_add_char(' ', str);
	if (p.space != 0 && p.point == 0 && n >= 0 && p.weigth_zero == 1
		&& p.weigth_n > 0)
	{
		if (p.weigth_n <= ft_intlen(n))
			str = ft_left_add_char(' ', str);
		else
			str[0] = ' ';
	}
	return (str);
}

size_t	size_fill(t_print p, size_t size, int n)
{
	if (p.point == 1)
		size = p.prec - ft_intlen(n);
	else if (p.point == 0 && n < 0)
		size = p.weigth_n - ft_intlen(n) - 1;
	else if (p.weigth_n > ft_intlen(n))
		size = p.weigth_n - ft_intlen(n);
	else
		size = ft_intlen(n);
	return (size);
}
