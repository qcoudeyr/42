/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:11 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/14 13:49:05 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

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

static char	*get_the_line(char *tab)
{
}


char	*get_next_line(int fd)
{
	static char			*tab[10];
	struct gnlstruct	gnl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl.vread = read (fd, gnl.buf, BUFFER_SIZE);
	gnl.buf[gnl.vread] = 0;
	if (gnl.vread <= 0)
	{
		tab[fd] = NULL;
		return (tab[fd]);
	}
	else if (strchr(gnl.buf, "\n") != NULL)
		gnl.line = get_the_line(tab[fd]);
	else
	{
		gnl.line = strdup(gnl.buf);
		while (strchr(gnl.buf, "\n") == NULL && gnl.vread > 0)
		{
			gnl.vread = read (fd, gnl.buf, BUFFER_SIZE);
			gnl.buf[gnl.vread] = 0;
			gnl.line = ft_strjoin(gnl.line, gnl.buf);
		}
		if (gnl.vread == 0)
			return (gnl.line);
	}
	

	return (gnl.line);
}
