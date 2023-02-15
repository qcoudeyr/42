/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:52:08 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/15 16:14:16 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p;
	char	*s;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	s = (char *)src;
	p = (char *)dest;
	while (i < n)
	{
		*p = *s;
		p++;
		s++;
		i++;
	}
	return (dest);
}
