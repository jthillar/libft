/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:25:57 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/23 17:12:20 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	while (lst)
	{
		if ((new = malloc(sizeof(lst->content_size))) == NULL)
			return (NULL);
		f(lst->content);
		lst = lst->next;
	}
	free(lst);
	return (lst);
}
