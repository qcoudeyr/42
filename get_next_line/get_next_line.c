/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:11 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/18 19:41:21 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_new_tab(char *tab)
{
	char	*strtemp;
	int		i;
	int		j;

	i = 0;
	while (tab[i] && tab[i] != '\n')
		i++;
	if (tab[i] == '\n')
		i++;
	else if (tab[i] == 0)
	{
		tab = NULL;
		return (tab);
	}
	strtemp = malloc (sizeof(char) * (ft_strlen(tab) - i) + 2);
	j = 0;
	while (tab[i] != 0)
		strtemp[j++] = tab[i++];
	strtemp[j] = 0;
	free(tab);
	return (strtemp);
}

static char	*get_the_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (str);
	line = malloc(sizeof(char) * i + 2);
	i = 0;
	while (*str != '\n')
		line[i++] = *str++;
	line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*ft_read(int fd, char *str)
{
	struct s_gnlstruct	gnl;
	int					loop;

	loop = 0;
	gnl.vread = 1;
	gnl.buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!gnl.buf)
		return (NULL);
	while (!ft_strrchr(str, '\n') && gnl.vread > 0)
	{
		gnl.vread = read (fd, gnl.buf, BUFFER_SIZE);
		if (gnl.vread <= 0 && ft_strlen(str) < 1)
			break ;
		gnl.buf[gnl.vread] = 0;
		str = ft_strjoin(str, gnl.buf);
		loop++;
	}
	free(gnl.buf);
	if (gnl.vread <= 0 && loop == 0)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char			*tab[1024];
	struct s_gnlstruct	gnl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tab[fd] = ft_read(fd, tab[fd]);
	if (tab[fd] == NULL)
		return (tab[fd]);
	gnl.line = get_the_line(tab[fd]);
	tab[fd] = get_new_tab(tab[fd]);
	return (gnl.line);
}
