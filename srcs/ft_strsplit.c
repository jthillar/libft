/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:14:35 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/24 11:45:00 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static int	ft_strlen_word(char const *s, char c, int start)
{
	int	count;

	count = 0;
	while (s[start] != c && s[start] != '\0')
	{
		count++;
		start++;
	}
	return (count);
}

static char	*ft_fill_word(const char *s, char *av, int start, int len_word)
{
	int j;

	j = 0;
	while (j < len_word)
	{
		av[j] = s[start];
		j++;
		start++;
	}
	av[j] = '\0';
	return (av);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**av;
	int		len_word;
	int		i;
	int		k;

	if (s == NULL)
		return (NULL);
	i = 0;
	k = 0;
	if (!(av = (char**)ft_memalloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (s[i] && k <= ft_count_word(s, c))
	{
		if (s[i] == c)
			i++;
		else
		{
			len_word = ft_strlen_word(s, c, i);
			av[k] = ft_strnew(sizeof(char) * (len_word + 1));
			av[k] = ft_fill_word(s, av[k], i, len_word);
			i = i + len_word;
			k++;
		}
	}
	return (av);
}
