/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:44:16 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/21 20:51:30 by  qcoudeyr        ###   ########.fr       */
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
		while(access(t->fpath, X_OK) < 0)
		{
			i++;
			free(t->fpath);
			t->fpath = ft_strjoin(t->path[i], t->cmdlist[arg][0]);
		}
		if (access(t->fpath, X_OK) == 0)
			t->cmdlist[arg][0] = t->fpath;
		else
		{
			perror("Command not found !");
			free(t->fpath);
			exit(EXIT_FAILURE);
		}
		arg++;
	}
}

void	cmdformat(t_pp *t)
{
	int i;

	i = 0;
	t->cmdlist = ft_calloc((t->narg +1), sizeof(char **));
	while (i < t->narg)
	{
		t->cmdlist[i] = ft_split(t->cmd[i], ' ');
		i++;
	}
	t->cmdlist[i] = NULL;

}

void	ft_readarg(int argc, char **argv, t_pp *t)
{
	if (argc < 5)
	{
		ft_printf("Usage: <infile> <cmd1> <cmd2> <outfile>\n");
		exit(EXIT_FAILURE);

	}
	if (access(argv[1], R_OK) < 0)
	{
		if (errno == ENOENT)
			ft_printf("Input file does not exist.\n");
		else if (errno == EACCES)
			ft_printf("Input file is not readable or permission denied.\n");
		else
			perror("access");
		exit(EXIT_FAILURE);
	}
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
	t->path = ft_calloc(1, sizeof(char **));
	while (ft_strnstr(t->env[i], "PATH=", 6) == 0)
		i++;
	t->env[i] += 5;
	t->path = ft_split(t->env[i], ':');
	i = 0;
	while(t->path[i])
	{
		temp = ft_strdup(t->path[i]);
		free(t->path[i]);
		t->path[i] = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
}

void	pipeline(t_pp *t)
{
	int fd[2];
	pid_t pid;
	int fdd = 0;

	while (*t->cmdlist != NULL)
	{
		pipe(fd);
		if ((pid = fork()) == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (*(t->cmdlist + 1) != NULL)
				dup2(fd[1], 1);
			close(fd[0]);
			execve((*t->cmdlist)[0], *t->cmdlist, t->env);
			exit(1);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			fdd = fd[0];
			t->cmdlist++;
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pp	*t;
	void	*ptr;

	t = ft_calloc(1, sizeof(t_pp));
	t->env= env;

	parsing(t);
	ft_readarg(argc, argv, t);
	pipe(t->pipefd);
	ptr = t->cmdlist;
	pipeline(t);
	t->cmdlist = ptr;
	for (int i = 0; i <= t->narg + 1; i++)
		free(t->cmd[i]);
	for(int i = 0; t->path[i] != NULL; i++)
		free(t->path[i]);
	for(int i = 0; i < (t->narg +1); i++)
	{
			if (t->cmdlist[i] != NULL)
			{
				for(int y = 0; t->cmdlist[i][y] != NULL ; y++)
				free(t->cmdlist[i][y]);
			}
		free(t->cmdlist[i]);
	}
	free(t->infile);
	free(t->outfile);
	free(t->path);
	free(t);
	return (0);
}
