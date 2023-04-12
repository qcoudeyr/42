/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:11 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/12 20:59:46 by  qcoudeyr        ###   ########.fr       */
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
	tlen = ft_strlen(tab);
	while (tab[len] != '\n' && tab[len] != '\0')
		len++;
	if (tab[len] == '\n')
		len++;
	line = malloc(sizeof(char) * len + 1);
	ft_strlcpy(line, tab, len);
	tmp = malloc (sizeof(char) * (tlen - len + 1));
	ft_strlcpy(tmp, &tab[len], tlen - len);
	free(tab);
	ft_memcpy(tab, tmp, tlen - len + 1);
	free(tmp);
	return (line);
}


char	*get_next_line(int fd)
{
	static char			*tab[66000];
	struct gnlstruct	gnl;

	if (tab[fd] == NULL || *tab[fd] == 0)
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
			tab[fd] = malloc (sizeof(char) * (ft_strlen(gnl.line) +1));
			ft_memcpy(tab[fd], gnl.line, ft_strlen(gnl.line));
			free(gnl.line);
		}
	}
	gnl.line = get_the_line(tab[fd]);
	return (gnl.line);
}
