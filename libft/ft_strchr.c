/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <qcoudeyr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:52:02 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/07 16:25:38 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char *) s;
	while (*src)
	{
		if (*src == (char)c)
			return (src);
		src++;
	}
	if (*src == 0 && (char)c == 0)
		return ((char *)src);
	return (0);
}
