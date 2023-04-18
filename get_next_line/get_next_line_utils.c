/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:09 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/18 14:13:01 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	c;

	if (s == NULL || *s == 0)
		return (0);
	c = 0;
	while (*s != 0)
	{
		c++;
		s++;
	}
	return (c);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*src;

	src = NULL;
	if (s == NULL || *s == 0)
		return (NULL);
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (src);
}

char	*ft_strjoin(char *str1, const char *str2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(str2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str1)
		while (str1[++i] != '\0')
			str[i] = str1[i];
	while (str2[j] != '\0')
		str[i++] = str2[j++];
	str[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	str1 = NULL;
	return (str);
}
