/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:52 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/03/09 10:15:23 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;

	src = NULL;
	while (*s != 0)
	{
		if (*s == (char)c)
			src = (char *) s;
		s++;
	}
	if ((char)c == 0)
		src = (char *) s;
	if (src != NULL && *src == (char)c)
		return ((char *)src);
	return (NULL);
}
