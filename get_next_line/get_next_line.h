/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:   <qcoudeyr@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:06:54 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/23 12:39:59 by                  ###   ########.fr       */
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

int 	set_fd_line(char **fdline, int fd);
char	*ft_strnstr(const char *str, const char *tosearch, size_t len);
char	*get_next_line(int fd);
char	*get_linet(char *buf);
size_t	get_line_len(char *buf);

#endif

#ifndef BUFFER_SIZE
# define INT BUFFER_SIZE = 1024
#endif