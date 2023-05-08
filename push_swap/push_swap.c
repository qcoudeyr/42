/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:46:26 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/08 16:52:01 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minmax(t_ps *t, int *arr)
{
	t->vmin = arr[0];
	t->vmax = arr[0];
	t->i = 0;
	while (t->i < t->len_a)
	{
		if (arr[t->i] > t->vmax)
			t->vmax = arr[t->i];
		else if (arr[t->i] < t->vmin)
			t->vmin = arr[t->i];
		t->i++;
	}
}

int	ft_error(int argc, char **argv)
{
	if (argc < 2 || !argv[argc - 1])
		return (1);
	return (0);
}


void	ft_exit(t_ps *t, int v)
{
	if (v == 2)
	{
		ft_printf("\nError !\n\nAt least 2 value are the same\n\n\
Value = %i in pos = %i and %i\n", t->pa[t->i], t->i, t->j);
	}
	if (v == 1)
		ft_printf("Error !\n");

	free (t->pa);
	if (t->pb)
		free (t->pb);
	exit (0);
}

int	ft_issort(t_ps *t)
{
	int	len;

	if (t->len_a == 0)
		return (0);
	len = t->len_a -1;
	while (t->pa[len] > t->pa[len - 1] && len > 1)
		len--;
	if (len == 1 && t->pa[0] < t->pa[1])
		return (1);
	return (0);
}

void	ft_indexer(t_ps *t)
{
	t->pa = malloc (sizeof(int) * t->len_a +1);
	t->i = 0;
	while (t->i < t->len_a)
	{
		t->j = 0;
		t->pos = 1;
		while (t->j < t->len_a)
		{
			if (t->index[t->i] > t->index[t->j])
				t->pos++;
			if (t->index[t->i] == t->index[t->j] && t->j != t->i)
				return (ft_exit(t, 2));
			t->j++;
		}
		t->pa[t->i] = t->pos;
		t->i++;
	}
}

void	ft_init_1_args(char **argv, t_ps *t)
{
	t->len_b = 0;
	t->temp_split = ft_split(argv[1], ' ');
	t->pos = 0;
	while (t->temp_split[t->pos])
		t->pos++;
	t->index = ft_calloc(t->pos, sizeof(int));
	t->i = 0;
	while (t->temp_split[t->i])
	{
		if (ft_atoi(t->temp_split[t->i]) >= INT_MAX)
			ft_exit (t, 1);
		t->index[t->i] = ft_atoi(t->temp_split[t->i]);
		t->i++;
	}
	t->len_a = t->i;
	free(t->temp_split);
	t->pb = malloc(sizeof(int));
	t->pb[0] = 0;
	ft_indexer(t);
}

void	ft_init(int argc, char **argv, t_ps *t)
{
	t->len_b = 0;
	t->len_a = argc -1;
	t->index = malloc(sizeof(int) * (argc - 1));
	t->pb = malloc(sizeof(int));
	t->pb[0] = 0;
	if (t->pa == NULL)
		return ;
	t->i = 1;
	while (t->i < argc)
	{
		if (ft_atoi(argv[t->i]) >= INT_MAX)
			ft_exit (t, 1);
		t->index[t->i - 1] = ft_atoi(argv[t->i]);
		t->i++;
	}
	ft_indexer(t);
}

int	main(int argc, char **argv)
{
	struct t_ps	t_ps;

	if (ft_error(argc, argv) == 1)
		return (write(2, "Error\n", 6));
	if (argc == 2)
		ft_init_1_args(argv, &t_ps);
	else
		ft_init(argc, argv, &t_ps);
	if (!t_ps.pa)
		return (write(2, "Error!\n", 7));
	if (ft_issort(&t_ps) == 1)
		ft_exit(&t_ps, 0);
	ft_sort(&t_ps);
	ft_exit(&t_ps, 0);
	return (0);
}
