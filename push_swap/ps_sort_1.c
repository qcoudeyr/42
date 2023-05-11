/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:40:44 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/11 12:00:07 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_ps *t)
{
	if (t->len_a <= 5)
		sort_small(t);
	else if (t->len_a > 2)
		sort_array(t);
	return ;
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

void	sort_array(t_ps *t)
{
	t->p_a = 0;
	t->p_b = 0;
	push_b(t);
	push_b(t);
	if (t->pb[0] < t->pb[1])
		swap_pile(t, 'b');
	while (t->len_a > 0)
	{
		t->best[2] = t->len_a + t->len_b;
		minmax(t);
		set_min_push(t);
		t->p_a = t->best[0];
		t->p_b = t->best[1];
		while (t->p_a != 0 && t->p_b != 0 && t->p_a < t->len_a / 2 \
		&& t->p_b < t->len_b / 2)
		{
			rotate_pile(t, 'r');
			t->p_a--;
			t->p_b--;
		}
		do_op_on_a(t);
		do_op_on_b(t);
	}
	finish_sort(t);
}
