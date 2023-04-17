/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:06:54 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/14 13:22:11 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>

struct gnlstruct
{
char	buf[BUFFER_SIZE];
char	*line;
int		vread;
};
/*
char	*ft_strrchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
 */
#endif

#ifndef BUFFER_SIZE
# define INT BUFFER_SIZE = 1024
#endif
