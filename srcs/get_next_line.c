/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:40:18 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/06 17:23:59 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_strndup(char **s, int c)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen(*s);
	if (!(dest = ft_strnew(size + 1)))
		return (NULL);
	while ((*s)[i] != c && (*s)[i])
	{
		dest[i] = (*s)[i];
		i++;
	}
	dest[i] = '\0';
	ft_strdel(s);
	return (dest);
}

int		ft_realloc(char **rest)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(*rest))))
		return (0);
	tmp = ft_strcpy(tmp, *rest);
	ft_memdel((void **)rest);
	if (!(*rest = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	*rest = ft_strcpy(*rest, tmp);
	ft_memdel((void **)&tmp);
	tmp = NULL;
	return (1);
}

int		end_of_file(char **rest, char **str, char **line)
{
	unsigned int i;

	if (ft_strcmp(*rest, *str) == 0 && (*rest)[0] == '\0')
	{
		ft_strdel(str);
		ft_strdel(rest);
		return (0);
	}
	if (ft_strchr(*str, '\n'))
	{
		i = 0;
		while ((*str)[i] != '\n')
			i++;
		ft_strdel(rest);
		*rest = ft_strsub(*str, i + 1, ft_strlen(*str));
		*line = ft_strndup(str, '\n');
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(rest);
	}
	ft_strdel(str);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	static char		*rest = NULL;

	if (fd < 0 || (ret = read(fd, buf, 0)) == -1)
		return (-1);
	if (rest == NULL)
		rest = ft_strnew(0);
	str = ft_strdup(rest);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(ft_realloc(&str)))
			return (-1);
		str = ft_strcat(str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (end_of_file(&rest, &str, line));
}
