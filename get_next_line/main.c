/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:39:17 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/04/18 18:54:04 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void /* int argc, char *argv */)
{
	char	*line;
	int	fd1;
/* 	int fd_41_no_nl;
	int fd_41_with_nl;
	int fd_42_no_nl;
	int fd_42_with_nl;
	int fd_43_no_nl;
	int fd_43_with_nl;
	int fd_alternate_line_nl_no_nl;
	int fd_alternate_line_nl_with_nl;

	fd_41_no_nl = open("tests/41_no_nl", O_RDONLY);
	fd_41_with_nl = open("tests/41_with_nl", O_RDONLY);
	fd_42_no_nl = open("tests/42_no_nl", O_RDONLY);
	fd_42_with_nl = open("tests/42_with_nl", O_RDONLY);
	fd_43_no_nl = open("tests/43_no_nl", O_RDONLY);
	fd_43_with_nl = open("tests/43_with_nl", O_RDONLY);
	fd_alternate_line_nl_no_nl = open("tests/alternate_line_nl_no_nl", O_RDONLY);
	fd_alternate_line_nl_with_nl = open("tests/alternate_line_nl_with_nl", O_RDONLY);
 */
	fd1 = open("tests/variable_nls.txt", O_RDONLY);
	int i = 1;
	while ((line = get_next_line(fd1)) != NULL)
	{
	printf("variable_nls line [%02d]: %s", i++, line);
	free(line);
	}
	/* i = 0;
	while ((line = get_next_line(fd_41_with_nl)) != NULL)
	{
	printf("fd_41_with_nl line [%02d]: %s", i++, line);
	free(line);
	}
	i = 0;
	while ((line = get_next_line(fd_42_no_nl)) != NULL)
	{
	printf("fd_42_no_nl line [%02d]: %s", i++, line);
	free(line);
	}
	i = 0;
	while ((line = get_next_line(fd_42_with_nl)) != NULL)
	{
	printf("fd_42_with_nl line [%02d]: %s", i++, line);
	free(line);
	}
i = 0;

	while ((line = get_next_line(fd_43_no_nl)) != NULL)
	{
	printf("fd_43_no_nl line [%02d]: %s", i++, line);
	free(line);
	}
i = 0;

	while ((line = get_next_line(fd_43_with_nl)) != NULL)
	{
	printf("fd_43_with_nl line [%02d]: %s", i++, line);
	free(line);
	}
i = 0;

	while ((line = get_next_line(fd_alternate_line_nl_no_nl)) != NULL)
	{
	printf("fd_alternate_line_nl_no_nl line [%02d]: %s", i++, line);
	free(line);
	}
i = 0;

	while ((line = get_next_line(fd_alternate_line_nl_with_nl)) != NULL)
	{
	printf("fd_alternate_line_nl_with_nl line [%02d]: %s", i++, line);
	free(line);
	}
i = 0;


 */
close(fd1);
/*
	close(fd_41_no_nl);
	close(fd_41_with_nl);
	close(fd_42_no_nl);
	close(fd_42_with_nl);
	close(fd_43_no_nl);
	close(fd_43_with_nl);
	close(fd_alternate_line_nl_no_nl);
	close(fd_alternate_line_nl_with_nl);x */
	return (0);
}
