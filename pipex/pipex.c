/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:44:16 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/23 13:25:40 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve(t_pp *t, int i)
{
	dup2(t->file_fd[0], 0);
	dup2(t->pipefd[1], 1);
	if (t->cmdlist[i +1] == NULL)
		dup2(t->file_fd[1], 1);
	if (execve(t->cmdlist[i][0], t->cmdlist[i], t->env) == -1)
	{
		ft_perror(t, "execve");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}

void	pipeline(t_pp *t)
{
	int		i;

	i = 0;
	while (t->cmdlist[i] != NULL)
	{
		pipe(t->pipefd);
		t->pid = fork();
		if (t->pid == -1)
			ft_perror(t, "fork");
		else if (t->pid == 0)
			ft_execve(t, i);
		else
		{
			waitpid(t->pid, &t->status, WNOHANG);
			t->file_fd[0] = t->pipefd[0];
			close(t->pipefd[1]);
			i++;
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pp	*t;
	void	*ptr;

	if (*env == NULL)
	{
		ft_printf(COLOR_RED"No env detected !\n");
		exit(EXIT_FAILURE);
	}
	t = ft_calloc(1, sizeof(t_pp));
	t->env = env;
	parsing(t);
	ft_readarg(argc, argv, t);
	t->file_fd[0] = open(t->infile, O_RDONLY);
	if (t->file_fd[0] == -1 || t->file_fd[1] == -1)
		ft_perror(t, "open");
	ptr = t->cmdlist;
	pipeline(t);
	t->cmdlist = ptr;
	ft_free(t);
	return (0);
}
