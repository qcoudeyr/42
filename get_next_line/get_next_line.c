/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:11 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/11 12:13:13 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char			**tab;
	struct gnlstruct	gnl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (tab == NULL)
		tab = malloc(sizeof(char *) * 66000);
	if (tab[fd] != NULL && ft_strrchr(tab[fd], '\n') != NULL)
		tab[fd] = get_the_line(tab, gnl.line, fd);
	else
	{
		gnl.line = malloc (1);
		while (ft_strrchr(gnl.line, '\n') == NULL || gnl.vread > 0)
		{
			gnl.vread = read (fd, gnl.buf, BUFFER_SIZE);
			gnl.line = ft_strjoin(gnl.line, gnl.buf);
		}


		if (gnl.vread == 0)
		{
			free (tab[fd]);
			free (gnl.line)
			return (NULL);
		}

	}
	return (gnl.line);
}
