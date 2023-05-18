/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:06:54 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/05/11 12:06:03 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H



# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

struct	s_gnlstruct
{
	char	*buf;	vread;
	char	*line;
	int		vread;
};


char		*get_next_line(int fd);
char		*ft_strjoin(char *str1, char const *str2);

char		*ft_strrchr(const char *s, int c);

size_t		ft_strlen(const char *s);

#endif
