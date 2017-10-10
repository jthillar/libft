/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:41:04 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/18 18:47:56 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_print	fill_parse(char **fmt)
{
	t_print	parse;

	ft_bzero(&parse, sizeof(parse));
	flag_parse(&parse, fmt);
	weigth_parse(&parse, fmt);
	precision_parse(&parse, fmt);
	length_parse(&parse, fmt);
	type_parse(&parse, fmt);
	return (parse);
}
