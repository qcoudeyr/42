/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:50:11 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/13 14:10:12 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	value;
	int	neg;

	value = 0;
	neg = 1;
	while (ft_isspace(*(char *)str) == 1)
		str++;
	if (*(char *)str == '-')
	{
		neg *= -1;
		str++;
	}
	else if (*(char *)str == '+')
		str++;
	while (*(unsigned char *)str < 58 && *(unsigned char *)str > 47)
		value = (value * 10 + (*str++ - 48));
	return (value * neg);
}
