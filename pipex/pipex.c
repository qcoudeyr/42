/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:44:16 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/12 20:53:29 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_formatcmd(t_pp *t, int ncmd)
{
	char	**temp;
	int		i;

	temp = ft_split(t->cmdlist[ncmd], ' ');
	t->cmd = ft_strdup(temp[0]);
	if (temp[1] == NULL)
		return ;
	i = 1;
	t->larg = malloc(sizeof(char **));
	while (temp[i])
	{
		t->larg[i - 1] = ft_strdup(temp[i]);
		i++;
	}
	while (i >= 0)
	{
		free(temp[i]);
		i--;
	}
	free(temp);
}

void	ft_execmd(const char *cmd, char *args[], int input_fd, int output_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid >= 0)
	{
		dup2(input_fd, 0);
		dup2(output_fd, 1);
		close(input_fd);
		close(output_fd);
		execve(cmd, args, NULL);
		perror("execve");
	}
}

void	pipeline(char ***cmd)
{
	int fd[2];
	pid_t pid;
	int fdd = 0;

	while (*cmd != NULL) {
		pipe(fd);
		if ((pid = fork()) == -1
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (*(cmd + 1) != NULL)
				dup2(fd[1], 1);
			close(fd[0]);
			execvp((*cmd)[0], *cmd);
			exit(1);
		}
		else
		{
			wait(NULL); 		/* Collect childs */
			close(fd[1]);
			fdd = fd[0];
			cmd++;
		}
	}
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
	t->cmdlist = malloc(sizeof(char **) * 2);
	t->infile = ft_strdup(argv[1]);
	t->outfile = ft_strdup(argv[argc - 1]);
	t->narg = 0;
	while ((t->narg +2) <= (argc -2))
	{
		t->cmdlist[t->narg] = ft_strdup(argv[t->narg +2]);
		t->narg++;
	}
}

int	main(int argc, char **argv)
{
	t_pp	t;
	int		status;

	if (pipe(t.pipefd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	ft_readarg(argc, argv, &t);
	ft_formatcmd(&t, 0);
	pipeline()
/* 	ft_execmd(t.cmd, t.larg, open(t.infile, O_RDONLY), t.pipefd[1]);
	ft_execmd(t.cmd, t.larg, t.pipefd[0], STDOUT_FILENO); */
	close(t.pipefd[0]);
	close(t.pipefd[1]);
	wait(&status);
	wait(&status);
	for (int i = 0; i != t.narg; i++)
		free(t.cmdlist[i]);
	free(t.cmdlist);
	free(t.infile);
	free(t.outfile);
	return (0);
}
