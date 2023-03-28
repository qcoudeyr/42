/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:39:17 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/03/08 11:01:50 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

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

	if (get_next_line(-42) != NULL && get_next_line(-424422) != NULL)
		printf("FAIL TO RETURN NULL ON BAD FD SET\n");
	else
		printf("SUCCES TO RETURN NULL ON BAD FD SET\n");

	i = 0;
	while ((line = get_next_line(fd3)) != NULL)
	{
		/* printf("fd1 line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("fd2 line [%02d]: %s \n", i, line);
		free(line);
		line = get_next_line(fd3); */
		printf("fd3 line [%02d]: %s \n", i++, line);
		free(line);
	}



	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
