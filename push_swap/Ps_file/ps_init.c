/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:10:37 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/16 11:54:33 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ps_file/push_swap.h"

void	free_temp(t_ps *t)
{
	t->i = 0;
	while (t->temp_split[t->i])
		free(t->temp_split[t->i++]);
	free(t->temp_split);
}

void	ft_indexer(t_ps *t)
{
	free(t->pa);
	t->pa = ft_calloc(t->len_a +1, sizeof(int));
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
	free(t->index);
	t->index = NULL;
}

void	ft_init_1_args(char **argv, t_ps *t)
{
	t->len_b = 0;
	t->temp_split = ft_split(argv[1], ' ');
	t->pos = 0;
	while (t->temp_split[t->pos])
		t->pos++;
	t->index = ft_calloc(t->pos, sizeof(int));
	t->pa = ft_calloc(1, sizeof(int));
	t->pb = ft_calloc(1, sizeof(int));
	t->i = 0;
	while (t->temp_split[t->i])
	{
		if (ft_atoi(t->temp_split[t->i]) > INT_MAX || \
		ft_atoi(t->temp_split[t->i]) < INT_MIN)
		{
			free_temp(t);
			ft_exit (t, 1);
		}
		t->index[t->i] = ft_atoi(t->temp_split[t->i]);
		t->i++;
	}
	t->len_a = t->i;
	free_temp(t);
	ft_indexer(t);
}

void	ft_init(int argc, char **argv, t_ps *t)
{
	t->len_b = 0;
	t->len_a = argc -1;
	t->index = ft_calloc(argc - 1, sizeof(int));
	t->pa = ft_calloc(1, sizeof(int));
	t->pb = ft_calloc(1, sizeof(int));
	t->i = 1;
	while (t->i < argc)
	{
		if (ft_atoi(argv[argc - t->i]) > INT_MAX || \
		ft_atoi(argv[argc - t->i]) < INT_MIN)
			ft_exit (t, 1);
		t->index[t->i - 1] = ft_atoi(argv[t->i]);
		t->i++;
	}
	ft_indexer(t);
}
