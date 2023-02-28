/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:   <qcoudeyr@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:39:17 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/23 14:31:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int main(void /* int argc, char *argv */)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("tests/test1", O_RDONLY);
	fd2 = open("tests/test2", O_RDONLY);
	fd3 = open("tests/test3", O_RDONLY);

	if (get_next_line(42) != NULL && get_next_line(424422) != NULL)
		ft_putstr_fd("FAIL TO RETURN NULL ON BAD FD SET\n", 1);
	else
		ft_putstr_fd("SUCCES TO RETURN NULL ON BAD FD SET\n", 1);

	i = 0;
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("line [%02d]: %s", i++, line);
		free(line);	
	}
	i = 0;
	while (get_next_line(fd2) != NULL)
	{
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i++, line);
		free(line);	
	}
	i = 0;
	while (get_next_line(fd3) != NULL)
	{
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i++, line);
		free(line);	
	}
	
	
	
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}