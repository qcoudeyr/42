/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <qcoudeyr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:52:08 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/11 16:01:42 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	dif;

	if (n == 0)
		return (0);
	while (n > 0)
	{
		dif = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (dif != 0)
			break ;
		n--;
		s1++;
		s2++;
	}
	return (dif);
}
