/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:39:17 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/19 10:21:47 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
		char *line;
		int fd = open("read_error.txt", O_RDONLY);
		/* 1 */ line = get_next_line(fd);
		printf("%s", line);
		free(line);
		/* 2 */line = get_next_line(fd);
		printf("%s", line);
		free(line);
		if (BUFFER_SIZE > 100) {
			char *temp;
			do {
				temp = get_next_line(fd);
				free(temp);
			} while (temp != NULL);
		}
		/* 3 */ line = get_next_line(fd);
		printf("%s", line);
		free(line);
		close(fd);
		fd = open("read_error.txt", O_RDONLY);
		/* 4 */line = get_next_line(fd);
		printf("%s", line);
		free(line);
		/* 5 */line = get_next_line(fd);
		printf("%s", line);
		free(line);
		/* 6 */line = get_next_line(fd);
		printf("%s", line);
		free(line);
		/* 7 */line = get_next_line(fd);
		printf("%s", line);
		free(line);
		/* 8 */line = get_next_line(fd);
		printf("%s", line);
		free(line);
		close(fd);

	return (0);
}
