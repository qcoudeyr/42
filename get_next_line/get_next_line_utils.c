/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:09 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/14 11:34:20 by  qcoudeyr        ###   ########.fr       */
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
	int		len1;
	int		len2;
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return ((char *)s2);
	else if (s1 && !s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	tmp = str;
	while (*s1)
		*str++ = *(s1++);
	while (*s2)
		*str++ = *(s2++);
	*str = '\0';
	free(tmp - len1);
	tmp = NULL;
	return (str - len1);
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
	{
		return (NULL);
	}
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
