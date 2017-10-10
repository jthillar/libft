/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:49:14 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/21 18:35:01 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_chiffre(int n)
{
	int n_chiffre;
	int n_n;

	n_n = n;
	n_chiffre = 0;
	if (n_n == 0)
		return (1);
	if (n_n == -2147483648)
		return (11);
	if (n_n > -2147483648 && n_n < 0)
		n_chiffre++;
	while (n_n != 0)
	{
		n_n = n_n / 10;
		n_chiffre++;
	}
	return (n_chiffre);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		i;
	int		n_chiffre;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_chiffre = ft_count_chiffre(n) - 1;
	num = ft_strnew(sizeof(char) * (n_chiffre + 1));
	if (num == NULL)
		return (NULL);
	if (n > -2147483648 && n < 0)
	{
		num[i] = '-';
		n = n * -1;
		i = 1;
	}
	while (n_chiffre >= i)
	{
		num[n_chiffre] = n % 10 + 48;
		n = n / 10;
		n_chiffre--;
	}
	num[ft_strlen(num)] = '\0';
	return (num);
}
