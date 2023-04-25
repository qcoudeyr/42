/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:46:26 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/04/25 14:41:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minmax(t_ps *t)
{
	t->vmin = t->pa[0];
	t->vmax = t->pa[0];
	t->i = 0;
	while (t->i < t->len_a)
	{
		if (t->pa[t->i] > t->vmax)
			t->vmax = t->pa[t->i];
		else if (t->pa[t->i] < t->vmin)
			t->vmin = t->pa[t->i];
		t->i++;
	}
}

int	ft_error(int argc, char **argv)
{
	if (argc < 2 || !argv[argc - 1])
		return (1);
	return (0);
}

void	ft_indexer(t_ps *t)
{
	minmax(t);
	t->i = 0;
	t->index = malloc(sizeof(int) * t->len_a);
	while (t->i < t->len_a)
	{
		t->j = 0;
		t->pos = 1;
		while (t->j < t->len_a)
		{
			if (t->pa[t->i] > t->pa[t->j])
				t->pos++;
			t->j++;
		}
		t->index[t->i] = t->pos;
		t->i++;
	}
}

void	ft_init(int argc, char **argv, t_ps *t)
{
	t->len_b = 0;
	t->len_a = argc -1;
	t->pa = malloc(sizeof(int) * (argc - 1));
	if (t->pa == NULL)
		return ;
	t->i = 1;
	while (t->i < argc)
	{
		t->pa[t->i - 1] = ft_atoi(argv[t->i]);
		t->i++;
	}
	ft_indexer(t);
}

int	main(int argc, char **argv)
{
	struct t_ps	t_ps;

	if (ft_error(argc, argv) == 1)
		return (write(2, "Error\n", 6));

	ft_init(argc, argv, &t_ps);
	if (!t_ps.pa)
		return (write(2, "Error!\n", 7));
	t_ps.pb = malloc (sizeof(int) * (argc - 1));

	ft_printf("Pile_a \t|");
	ft_printf("\tIndex \n");
	for (int i = 0; i < (argc -1) ; i++)
	{
		ft_printf("  %i   \t|", t_ps.pa[i]);
		ft_printf("\t  %i \n", t_ps.index[i]);
	}
	ft_printf("\n");
	push_b(&t_ps);
	push_b(&t_ps);
	ft_printf("\n");

	ft_printf("\tPile_a \t\t|");
	ft_printf("\tPile_b \n");
	ft_printf("\t_______\t\t_\t_______\n");
	for (int i = 0; i < t_ps.len_a ; i++)
	{
		ft_printf("\t  %i \t\t|", t_ps.pa[i]);
		if (i < t_ps.len_b)
			ft_printf("\t  %i \n", t_ps.pb[i]);
		else
			ft_printf("\t  \n");
	}

	free (t_ps.pa);
	free (t_ps.pb);
	return (0);
}
