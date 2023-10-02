/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:25:39 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/28 13:14:14 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pathfinder(t_pp *t)
{
	int	i;
	int	arg;

	arg = 0;
	while (arg < t->narg)
	{
		i = 0;
		t->fpath = ft_strjoin(t->path[i], t->cmdlist[arg][0]);
		while (access (t->fpath, X_OK) < 0 && t->path[i + 1] != NULL)
		{
			i++;
			free(t->fpath);
			t->fpath = ft_strjoin(t->path[i], t->cmdlist[arg][0]);
		}
		if (access(t->fpath, X_OK) == 0)
		{
			free(t->cmdlist[arg][0]);
			t->cmdlist[arg][0] = ft_strdup(t->fpath);
		}
		else
			ft_cmdnotfound(t);
		arg++;
		free(t->fpath);
		t->fpath = NULL;
	}
}

void	cmdformat(t_pp *t)
{
	int		i;

	i = 0;
	t->cmdlist = ft_calloc((t->narg +1), sizeof(char **));
	while (i < t->narg)
	{
		if (ft_isalpha(*t->cmd[i]) == 0)
		{
			ft_printf(COLOR_RED "Command can't \
start with : '%c' !\n", *t->cmd[i]);
			ft_perror(t, 0);
		}
		t->cmdlist[i] = ft_splitq(t->cmd[i]);
		i++;
	}
}

void	ft_readarg(int argc, char **argv, t_pp *t)
{
	if (argc < 5)
	{
		ft_printf("Usage: <infile> <cmd1> <cmd2> <outfile>\n");
		ft_free(t);
		exit(EXIT_FAILURE);
	}
	t->outfile = ft_strdup(argv[argc - 1]);
	t->file_fd[1] = open(t->outfile, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | \
S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (access(argv[1], R_OK) < 0)
		ft_acceserror(t);
	t->cmd = ft_calloc(sizeof(char **), (argc - 1));
	t->infile = ft_strdup(argv[1]);
	t->outfile = ft_strdup(argv[argc - 1]);
	t->narg = 0;
	while ((t->narg +2) <= (argc -2))
	{
		t->cmd[t->narg] = ft_strdup(argv[t->narg +2]);
		t->narg++;
	}
	t->cmd[t->narg] = NULL;
	cmdformat(t);
	pathfinder(t);
}

void	parsing(t_pp *t)
{
	int		i;
	char	*temp;

	i = 0;
	while (ft_strnstr(t->env[i], "PATH=", 6) == 0)
		i++;
	t->env[i] += 5;
	t->path = ft_split(t->env[i], ':');
	i = 0;
	while (t->path[i])
	{
		temp = ft_strdup(t->path[i]);
		free(t->path[i]);
		t->path[i] = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
}
