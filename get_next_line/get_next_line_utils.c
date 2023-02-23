/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:   <qcoudeyr@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:09 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/23 12:39:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strnstr(const char *str, const char *tosearch, size_t len)
{
	int		n;
	char	*ptr;	
	size_t	i;

	if (!tosearch || *tosearch == 0)
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		n = 0;
		ptr = (char *)&str[i];
		while (str[i + n] == tosearch[n] && i + n < len)
		{
			if (tosearch[n +1] == 0)
				return (ptr + n+1);
			n++;
		}
		i++;
	}
	return (NULL);
}


size_t	get_line_len(char *buf)
{
	size_t	i;

	i = 0;
	while (*buf != '\0' && *buf++ != '\n')
		i++;
	return (i);
}

char	*get_linet(char *buf)
{
	char	*str;
	int		i;

	i = get_line_len(buf);
	str = malloc(sizeof(char) * (i+2));
	if (!str++)
		return (NULL);
	while (*buf != '\0' && *buf != '\n')
		*str++ = *buf++;
	*str = *buf;
	return (str - i);

}

int	set_fd_line(char **fdline, int fd)
{
	int	index;

	index = 0;
	if (fdline[index])
	{
		while (fdline[index] && fdline[index][0] != fd)
			index++;
		if (fdline[index][0] == fd)	
			return (index);
	}
	else
	{
		fdline[index] = malloc(sizeof(char) * 2);
		fdline[index][0] = fd;
	}
	return (index);

}
