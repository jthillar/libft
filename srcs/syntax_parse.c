/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 10:59:11 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/18 18:46:27 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_parse(t_print *parse, char **fmt)
{
	int j;

	j = 0;
	while ((*fmt)[j] && ((*fmt)[j] == '-' || (*fmt)[j] == '+' ||
	(*fmt)[j] == ' ' || (*fmt)[j] == '#' || (*fmt)[j] == '0'))
	{
		if ((*fmt)[j] == '0')
			parse->weigth_zero = 1;
		else if ((*fmt)[j] == '-')
			parse->minus = 1;
		else if ((*fmt)[j] == '+')
			parse->plus = 1;
		else if ((*fmt)[j] == ' ')
			parse->space = 1;
		else
			parse->htag = 1;
		j++;
	}
	*fmt += j;
}

void	weigth_parse(t_print *parse, char **fmt)
{
	int j;

	j = 0;
	if (ft_isdigit((*fmt)[j]) == 1)
	{
		while ((*fmt)[j] >= '0' && (*fmt)[j] <= '9')
		{
			parse->weigth_n = parse->weigth_n + (*fmt)[j] - 48;
			if ((*fmt)[j + 1] >= '0' && (*fmt)[j + 1] <= '9')
				parse->weigth_n = parse->weigth_n * 10;
			j++;
		}
	}
	if ((*fmt)[j] == '*')
	{
		parse->star_1 = 1;
		j++;
	}
	*fmt += j;
}

void	precision_parse(t_print *parse, char **fmt)
{
	int j;

	j = 0;
	if ((*fmt)[j] == '.')
	{
		parse->point = 1;
		j++;
		if ((*fmt)[j] >= '0' && (*fmt)[j] <= '9')
		{
			while ((*fmt)[j] >= '0' && (*fmt)[j] <= '9')
			{
				parse->prec = parse->prec + (*fmt)[j] - 48;
				if ((*fmt)[j + 1] >= '0' && (*fmt)[j + 1] <= '9')
					parse->prec = parse->prec * 10;
				j++;
			}
		}
		if ((*fmt)[j] == '*')
		{
			parse->star_2 = 1;
			j++;
		}
	}
	*fmt += j;
}

void	length_parse(t_print *parse, char **fmt)
{
	int j;

	j = 0;
	if ((*fmt)[j] == 'j' || (*fmt)[j] == 'z')
	{
		if ((*fmt)[j] == 'j')
			parse->j = 1;
		if ((*fmt)[j] == 'z')
			parse->z = 1;
		j++;
	}
	if ((*fmt)[j] == 'h')
	{
		j -= 1;
		while ((*fmt)[++j] == 'h')
			parse->h++;
	}
	if ((*fmt)[j] == 'l')
	{
		j -= 1;
		while ((*fmt)[++j] == 'l')
			parse->l++;
	}
	*fmt += j;
}

void	type_parse(t_print *parse, char **fmt)
{
	int j;

	j = 0;
	parse->c = (*fmt)[j];
	j++;
	*fmt += j;
}
