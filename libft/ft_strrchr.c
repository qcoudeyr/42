/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <qcoudeyr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:52 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/11 12:34:01 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;

	while (*s != 0)
	{
		if (*s == (char)c)
			src = (char *) s;
		s++;
	}
	if (c == 0)
		src = (char *) s;
	if (*src == (char)c)
		return ((char *)src);
	return (NULL);
}
