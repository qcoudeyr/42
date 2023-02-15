/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:51 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/15 17:07:34 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	int					i;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = len;
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (malloc(0));
	s = s + start;
	while (i-- > 0)
		*str++ = *(char *)s++;
	*str = 0;
	return (str - len);
}
