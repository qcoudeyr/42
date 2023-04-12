/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:09 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/12 20:45:02 by  qcoudeyr        ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		len;

	if ((!s1 && !s2) || (*s1 == 0 && *s2 == 0))
	{
		str = malloc(sizeof(char) * 1);
		str[0] = 0;
		return (str);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1 && *s1)
		*str++ = *(char *)s1++;
	while (s2 && *s2)
		*str++ = *(char *)s2++;
	*str = 0;
	free(s1);
	s1 = NULL;
	return (str - len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p;
	char	*s;
	size_t	i;

	if (dest == NULL || src == NULL || (char *)src == 0 || (char *)dest == 0)
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
