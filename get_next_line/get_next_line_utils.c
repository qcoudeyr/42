/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:09 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/11 19:46:15 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	c;

	if (s == NULL)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1 && *s1)
		*str++ = *(char *)s1++;
	while (s2 && *s2)
		*str++ = *(char *)s2++;
	*str = 0;
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


void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	if (d > s)
	{
		d += n - 1;
		s += n - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	else
		while (n-- > 0)
			*d++ = *s++;
	return (dest);
}
