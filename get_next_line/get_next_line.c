/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:   <qcoudeyr@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:11 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/23 12:41:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	**fdline;
	char		buf[BUFFER_SIZE];
	int			index;
	char		*ptr;

	index = 0;
	if (fdline){}
	else
		fdline = malloc(sizeof(char *) * 1);
	if (read(fd, buf, BUFFER_SIZE) == -1)
		return (NULL);
	index = set_fd_line(fdline, fd);
	ptr = ft_strnstr(buf, fdline[index], BUFFER_SIZE);
	if (ptr != NULL) 
		fdline[index] = get_linet(ptr);
	else
		fdline[index] = get_linet(buf);
	if (!fdline[index])
		return (NULL);
	return (fdline[index]);
}
