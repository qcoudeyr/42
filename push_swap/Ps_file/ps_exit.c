/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:16:59 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/18 11:36:36 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ps_file/push_swap.h"

int	ft_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = argc;
	if (argc == 1)
		exit (0);
	if (!argv[argc - 1])
		return (1);
	while (j >= 2)
	{
		while (argv[j -1][i])
		{
			if (ft_isdigit(argv[j -1][i]) == 0 && \
			argv[j -1][i] != 32 && argv[j -1][i] != '-')
				return (1);
			i++;
		}
		j--;
	}
	return (0);
}

void	ft_exit(t_ps *t, int v)
{
	if (v == 2)
	{
		write(2, "Error\n", 7);
		ft_printf("\n\nAt least 2 value are the same\n\
At pos = %i and pos = %i\n", t->i +1, t->j +1);
	}
	if (v == 1)
		write(2, "Error\n", 7);
	free (t->pa);
	free (t->pb);
	if (t->index)
		free(t->index);
	exit (0);
}
