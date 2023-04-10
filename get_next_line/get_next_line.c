/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:11 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/04 11:42:24 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **tab, char *line, int fd)
{
	free(line);
	free(tab[fd]);
	line = NULL;
	tab[fd] = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char			**tab;
	struct gnlstruct	gnl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (tab == NULL)
		tab = malloc(sizeof(char *) * 66000);
	gnl.line = malloc(sizeof(char) * 1);
	gnl.line[0] = 0;
	if (tab[fd] != NULL && ft_strrchr(tab[fd], '\n') != NULL)
	{
		gnl.index = 0;
		while (*(tab[fd] + gnl.index) != '\n')
			gnl.index++;
		gnl.line = malloc (sizeof(char) * (gnl.index + 1));
		ft_strlcpy(gnl.line, tab[fd], gnl.index + 1);
		tab[fd] = ft_strdup(tab[fd] + gnl.index + 1);
		return (gnl.line);
	}
	else if (tab[fd] != NULL)
		gnl.line = ft_strdup(tab[fd]);

	while (1)
	{
		gnl.vread = read(fd, gnl.buf, BUFFER_SIZE);
		if (gnl.vread == -1)
			return (ft_free(tab, gnl.line, fd));
		gnl.buf[gnl.vread] = 0;
		gnl.line = ft_strjoin(gnl.line, gnl.buf);
		if (ft_strrchr(gnl.buf, '\n') != NULL)
			break ;
		if (gnl.vread == 0)
			break ;
	}
	gnl.index = 0;
	while (gnl.line[gnl.index] != '\n' && gnl.line[gnl.index] != 0)
		gnl.index++;
	if (gnl.line[gnl.index] == '\n')
	{
		tab[fd] = ft_strdup(gnl.line + gnl.index + 1);
		gnl.line[gnl.index + 1] = 0;
	}
	else
		tab[fd] = ft_strdup("");
	return (gnl.line);
}
