/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:40:44 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/08 16:41:40 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_ps *t)
{
	if (t->len_a == 2)
		swap_pile(t, 'a');
	else if (t->len_a > 2)
		sort_array(t);
	return ;
}

int	ft_isrevsort(int *arr, int len)
{
	int	i;

	i = 0;
	if (len <= 1)
		return (1);
	while (arr[i] > arr[i + 1] && i < len - 1)
		i++;
	if (arr[i] > arr[i + 1] && i + 1 == len)
		return (1);
	else
		return (0);
}

void	quick_sort(t_ps *t)
{
	int	median;

	minmax(t, t->pa);
	median = t->vmax / 2;
	t->i = 0;
	while (t->i < t->len_a - 1)
	{
		if (t->pa[0] < median)
			push_b(t);
		else
			rotate_pile(t, 'a');
		t->i++;
	}
	while (t->len_b > 0)
		push_a(t);
}

void	sort_array(t_ps *t)
{
	int	size;
	int	i;
	int	j;

	size = t->len_a;
	i = 0;
	while (ft_issort(t) == 0 && i < t->len_a)
	{
		j = 1;
		while (j < size + 1)
		{
			if (((t->pa[0] >> i) & 1) == 1)
				rotate_pile(t, 'a');
			else if (ft_issort(t) == 1)
				break ;
			else
			{
				push_b(t);

			}
			j++;
		}
		while (t->len_b > 0)
			push_a(t);
		i++;
	}
}
