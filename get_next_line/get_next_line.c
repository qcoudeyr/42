/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:11 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/13 12:50:15 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_the_line(char *tab)
{
	char	*line;
	int		len;
	int		tlen;
	char	*tmp;

	if (tab == NULL)
		return (NULL);
	len = 0;
	if (*tab == 0)
		tlen = 0;
	else
		tlen = ft_strlen(tab);
	while (tab[len] != '\n' && tab[len] != '\0')
		len++;
	if (tab[len] == '\n')
		len++;
	line = malloc(sizeof(char) * len + 1);
	ft_strlcpy(line, tab, len + 1);
	tmp = malloc (sizeof(char) * (tlen - len + 1));
	ft_strlcpy(tmp, &tab[len], tlen - len);
	free(tab);
	ft_memcpy(tab, tmp, tlen - len + 1);
	free(tmp);
	return (line);
}


char	*get_next_line(int fd)
{
	static char			*tab[10];
	struct gnlstruct	gnl;

	if (tab[fd] == NULL || !*tab[fd])
	{
		tab[fd] = malloc (sizeof (char));
		tab[fd][0] = 0;
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strrchr(tab[fd], '\n') == NULL)
	{
		while (ft_strrchr(tab[fd], '\n') == NULL)
		{
			gnl.vread = read (fd, gnl.buf, BUFFER_SIZE);
			if (gnl.vread == 0)
			{
				if (tab[fd] != NULL)
					free(tab[fd]);
				tab[fd] = NULL;
				return (NULL);
			}
			gnl.buf[gnl.vread] = 0;
			gnl.line = ft_strjoin(tab[fd], gnl.buf);
			tab[fd] = calloc ((ft_strlen(gnl.line) + 1), sizeof(char));
			tab[fd] = ft_strjoin(tab[fd], gnl.line);
			free(gnl.line);
		}
	}
	gnl.line = get_the_line(tab[fd]);
	return (gnl.line);
}
