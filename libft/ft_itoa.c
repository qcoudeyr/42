/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:48 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/13 14:50:38 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	ft_intlen(int n, int *pwr)
{
	int	len;

	len = 0;
	*pwr = 1;
	if (n < 0)
	{
		len += 1;
		n *= -1;
	}
	while (n != 0)
	{
		if (n > 9)
			*pwr *= 10;
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		pwr;
	int		index;
	long	val;

	index = 0;
	val = n;
	str = malloc(sizeof(char) * ft_intlen(val, &pwr) + 1);
	if (!str)
		return (NULL);
	if (val < 0)
	{
		str[index++] = '-';
		val *= -1;
	}
	while (pwr != 1)
	{
		str[index++] = (val / pwr) + 48;
		val %= pwr;
		pwr /= 10;
	}
	str[index++] = val +48;
	str[index] = 0;
	return (str);
}
