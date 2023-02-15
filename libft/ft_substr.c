/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <qcoudeyr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:51 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/07 12:23:47 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = len;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	s = s + start;
	while (i-- > 0)
	{
		*str++ = *(char *)s++;
	}
	*str = 0;
	return (str - len);
}
