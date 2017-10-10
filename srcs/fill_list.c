/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:27:41 by jthillar          #+#    #+#             */
/*   Updated: 2017/07/20 15:37:52 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	*list_remove_first(t_str *list)
{
	t_str *first;

	first = list;
	ft_memdel((void**)&first->str);
	list = list->next;
	free(first);
	return (list);
}

void	ft_free_list(t_str *list)
{
	while (list)
		list = list_remove_first(list);
}

t_str	*init_list(void)
{
	t_str	*list;

	if (!(list = (t_str*)malloc(sizeof(t_str))))
		return (NULL);
	if (list)
	{
		list->str = NULL;
		list->ret = 0;
		list->next = NULL;
	}
	return (list);
}

void	add_list_del_str(t_str *list, char *str)
{
	add_list(list, ft_strlen(str), str);
	if (str)
		ft_memdel((void**)&str);
}

int		add_list(t_str *list, int size, char *fmt)
{
	if (list->str)
	{
		while (list && list->next)
			list = list->next;
		if (!(list->next = (t_str*)malloc(sizeof(t_str))))
			return (0);
		list = list->next;
	}
	if (!(list->str = ft_strnew(size)))
		return (0);
	ft_strncpy(list->str, fmt, size);
	list->ret = size;
	list->next = NULL;
	return (1);
}
