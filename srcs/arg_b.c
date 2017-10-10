/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 18:09:34 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/18 18:16:05 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_b(unsigned int n, t_str *list)
{
	char	*str;

	str = ft_itoabase(n, 2);
	str = ft_left_add_char('b', str);
	str = ft_left_add_char('0', str);
	add_list(list, ft_strlen(str), str);
}
