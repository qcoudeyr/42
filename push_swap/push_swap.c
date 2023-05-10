/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:46:26 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/09 12:27:44 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (ft_isdigit(argv[j -1][i]) == 0 && argv[j -1][i] != 32)
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
		ft_printf("\nError !\n\nAt least 2 value are the same\n\
At pos = %i and pos = %i\n", t->i +1, t->j +1);
	}
	if (v == 1)
		ft_printf("Error !\n");
	free (t->pa);
	free (t->pb);
	if (t->index)
		free(t->index);
	exit (0);
}

int	main(int argc, char **argv)
{
	struct t_ps	t_ps;

	if (ft_error(argc, argv) == 1)
		return (write(2, "Error\n", 6));
	else if (argc == 2)
		ft_init_1_args(argv, &t_ps);
	else if (argc > 2)
		ft_init(argc, argv, &t_ps);
	if (!t_ps.pa)
		return (write(2, "Error!\n", 7));
	if (ft_issort(&t_ps) == 1)
		ft_exit(&t_ps, 0);
	ft_sort(&t_ps);
	ft_exit(&t_ps, 0);
	return (0);
}
