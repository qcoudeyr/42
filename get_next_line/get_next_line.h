/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:06:54 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/18 19:39:19 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

struct	s_gnlstruct
{
	char	*buf;
	char	*line;
	int		vread;
};

char		*get_next_line(int fd);

char		*ft_strrchr(const char *s, int c);
char		*ft_strjoin(char *str1, char const *str2);
size_t		ft_strlen(const char *s);

#endif
