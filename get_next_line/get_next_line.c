/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:11 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/11 20:33:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_the_line(char *tab)
{
	char	*line;
	int		len;

	if (tab == NULL)
		return (NULL);
	len = 0;
	while (tab[len] != '\n' && tab[len] != '\0')
		len++;
	line = malloc(sizeof(char) * len +2);
	ft_strlcpy(line, tab, len +2);
	if (tab[len] == '\n')
		len++;
	ft_memmove(tab, &tab[len], ft_strlen(tab) - len + 1);
	return (line);
}


char	*get_next_line(int fd)
{
	static char			*tab[66000];
	struct gnlstruct	gnl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (tab[fd] == NULL || ft_strrchr(tab[fd], '\n') == NULL)
	{
		tab[fd] = ft_strjoin(tab[fd], "");
		while (ft_strrchr(tab[fd], '\n') == NULL)
		{
			gnl.vread = read (fd, gnl.buf, BUFFER_SIZE);
			if (gnl.vread == 0)
				break ;
			gnl.buf[gnl.vread] = 0;
			tab[fd] = ft_strjoin(tab[fd], gnl.buf);
		}
		if (gnl.vread == 0 && *tab[fd] == 0)
		{
			free(tab[fd]);
			tab[fd] = NULL;
		}
	}
	return (get_the_line(tab[fd]));
}
