/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:22:51 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/28 13:12:54 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmdnotfound(t_pp *t)
{
	perror("Command not found !");
	ft_free(t);
	exit(EXIT_FAILURE);
}

void	ft_acceserror(t_pp *t)
{
	if (errno == ENOENT)
		ft_printf("Input file does not exist.\n");
	else if (errno == EACCES)
		ft_printf("Input file is not readable or permission denied.\n");
	else
		ft_perror(t, "access");
	ft_free(t);
	exit(EXIT_FAILURE);
}

void	ft_perror(t_pp *t, char *s)
{
	if (s != NULL)
		perror(s);
	write(t->file_fd[1], "1", 1);
	ft_free(t);
	exit(EXIT_FAILURE);
}

void	ft_freecmdlist(t_pp *t)
{
	int	i;
	int	y;

	i = 0;
	if (t->cmdlist != NULL)
	{
		while (i < (t->narg + 1))
		{
			if (t->cmdlist[i] != NULL)
			{
				y = 0;
				while (t->cmdlist[i][y] != NULL)
					free(t->cmdlist[i][y++]);
			}
			free(t->cmdlist[i]);
			i++;
		}
		free(t->cmdlist);
	}
}

void	ft_free(t_pp *t)
{
	int	i;

	i = 0;
	if (t->cmd != NULL)
	{
		while (i <= t->narg + 1)
		{
			free(t->cmd[i]);
			i++;
		}
		free(t->cmd);
	}
	i = 0;
	while (t->path[i] != NULL)
		free(t->path[i++]);
	free(t->path);
	ft_freecmdlist(t);
	free(t->infile);
	free(t->outfile);
	if (t->fpath != NULL)
		free(t->fpath);
	free(t);
}
