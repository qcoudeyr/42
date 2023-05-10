/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:45:39 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/10 11:31:40 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_ps *t)
{
	if (t->len_a == 2)
		return (swap_pile(t, 'a'));
	else if (t->len_a == 3)
	{
		while (ft_issort(t) != 1)
		{
			if (t->pa[2] == 3)
				swap_pile(t, 'a');
			else if (t->pa[1] == 3)
				rrotate_pile(t, 'a');
			else if ((t->pa[0] == 3))
				rotate_pile(t, 'a');
		}
	}
	else if (t->len_a > 3)
		sort_small_5(t);
	return ;
}

void	sort_small_5(t_ps *t)
{
	minmax(t);
	if (t->pa[1] == t->vmax || t->pa[1] == t->vmin)
		rotate_pile(t, 'a');
	while (ft_issort(t) != 1)
	{
		if ((t->pa[0] == t->vmax || t->pa[0] == t->vmin) && t->len_b == 0)
			push_b(t);
		if (t->pa[1] < t->pa[2] && t->pa[2] < t->pa[0])
		{
			swap_pile(t, 'a');
			rotate_pile(t, 'a');
			swap_pile(t, 'a');
		}
		if (t->pa[0] < t->pa[1])
			rrotate_pile(t, 'a');
		else
			swap_pile(t, 'a');
	}
	if (t->len_b > 0)
	{
		push_a(t);
		if (ft_issort(t) != 1)
			rotate_pile(t, 'a');
	}
	return ;
}
