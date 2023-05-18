/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:54:02 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/18 12:19:56 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ps_file/push_swap.h"

void	compare_op(t_ps *t)
{
	if (t->p_a > (t->len_a / 2))
		t->sum = t->len_a - t->p_a;
	else
		t->sum = t->p_a;
	if (t->p_b > t->len_b / 2)
		t->sum += t->len_b - t->p_b;
	else
		t->sum += t->p_b;
	if (t->p_b == t->len_b)
		t->p_b = 0;
	if (t->sum < t->best[2])
	{
		t->best[0] = t->p_a;
		t->best[1] = t->p_b;
		t->best[2] = t->sum;
	}
}

void	set_min_push(t_ps *t)
{
	while (t->p_a < t->len_a)
	{
		if (t->pa[t->p_a] < t->pb[t->bmin])
			t->p_b = t->bmin + 1;
		else if (t->pa[t->p_a] > t->pb[t->bmax])
			t->p_b = t->bmax;
		else
		{
			while (t->pa[t->p_a] > t->pb[t->p_b] && t->p_b < t->len_b)
				t->p_b++;
			while (t->pa[t->p_a] < t->pb[t->p_b] && t->p_b < t->len_b)
				t->p_b++;
		}
		compare_op(t);
		t->p_b = 0;
		t->p_a++;
	}
}

void	do_op_on_a(t_ps *t)
{
	while (t->p_a != 0 && t->p_b != 0 && t->p_a > t->len_a / 2 \
	&& t->p_b > t->len_b / 2)
	{
		rrotate_pile(t, 'r');
		t->p_a++;
		t->p_b++;
		if (t->p_a == t->len_a)
			t->p_a = 0;
		if (t->p_b == t->len_b)
			t->p_b = 0;
		if (t->p_a == 0 && t->p_b != 0 && t->p_b < t->len_b / 2)
			t->p_b--;
	}
	while (t->p_a != 0 && t->p_a > t->len_a / 2 && t->p_a < t->len_a)
	{
		rrotate_pile(t, 'a');
		t->p_a++;
		if (t->p_a == t->len_a)
			t->p_a = 0;
	}
	while (t->p_a != 0)
	{
		rotate_pile(t, 'a');
		t->p_a--;
	}
}

void	do_op_on_b(t_ps *t)
{
	while (t->p_b != 0 && t->p_b > t->len_b / 2 && t->p_b < t->len_b)
	{
		rrotate_pile(t, 'b');
		t->p_b++;
		if (t->p_b == t->len_b)
			t->p_b = 0;
	}
	while (t->p_b != 0)
	{
		rotate_pile(t, 'b');
		t->p_b--;
	}
	if (t->p_a == 0)
		push_b(t);
}

void	finish_sort(t_ps *t)
{
	minmax(t);
	while (t->bmax != 0)
	{
		minmax(t);
		if (t->bmax > (t->len_b / 2))
			rrotate_pile(t, 'b');
		else if (t->bmax <= (t->len_b / 2) && t->bmax != 0)
			rotate_pile(t, 'b');
	}
	while (t->len_b > 0)
		push_a(t);
}
