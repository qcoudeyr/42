/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <qcoudeyr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:52:07 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/07 14:57:58 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (d > s)
	{
		d += n - 1;
		s += n - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	else
		while (n-- > 0)
			*d++ = *s++;
	return (dest);
}
