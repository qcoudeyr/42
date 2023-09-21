/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:44:14 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/21 14:19:57 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int		input_fd;
	int		output_fd;
	char	***cmdlist;
	char	*infile;
	char	*outfile;
	char	**larg;
	char	**cmd;
	int		narg;
	char	*fpath;
	int		pipefd[2];
	char	**env;
	char	**path;
}	t_pp;

#endif
