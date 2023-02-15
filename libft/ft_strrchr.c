/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:52 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/13 23:30:28 by qcoudeyr         ###   ########.fr       */
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
	if (c == 0)
		src = (char *) s;
	if (src != NULL && *src == (char)c)
		return ((char *)src);
	return (NULL);
}
