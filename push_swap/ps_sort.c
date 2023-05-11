/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:40:44 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/11 11:16:53 by  qcoudeyr        ###   ########.fr       */
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
	int i, j, sum;
	int tab[3] = {0};

	i = 0;
	j = 0;
	push_b(t);
	push_b(t);
	if (t->pb[0] < t->pb[1])
		swap_pile(t, 'b');
	while (t->len_a > 0)
	{
		tab[2] = t->len_a + t->len_b;
		minmax(t);
		while (i < t->len_a)
		{
			if (t->pa[i] < t->pb[t->bmin])
				j = t->bmin + 1;
			else if (t->pa[i] > t->pb[t->bmax])
				j = t->bmax;
			else
			{
				while (t->pa[i] > t->pb[j] && j < t->len_b)
					j++;
				while (t->pa[i] < t->pb[j] && j < t->len_b)
					j++;
			}
			if (i > (t->len_a / 2))
				sum = t->len_a - i;
			else
				sum = i;
			if (j > t->len_b / 2)
				sum += t->len_b - j;
			else
				sum += j;
			if (j == t->len_b)
				j = 0;
			if (sum < tab[2])
			{
				tab[0] = i;
				tab[1] = j;
				tab[2] = sum;
			}
			j = 0;
			i++;
		}
		i = tab[0];
		j = tab[1];
		while (i != 0 && j != 0 && i < t->len_a / 2 && j < t->len_b / 2)
		{
			rotate_pile(t, 'r');
			i--;
			j--;
		}
		while (i != 0 && j != 0 && i > t->len_a / 2 && j > t->len_b / 2)
		{
			rrotate_pile(t, 'r');
			i++;
			j++;
			if (i == t->len_a)
				i = 0;
			if (j == t->len_b)
				j = 0;
			if (i == 0 && j != 0 && j < t->len_b / 2)
				j--;
		}

		while (i != 0 && i > t->len_a / 2 && i < t->len_a)
		{
			rrotate_pile(t, 'a');
			i++;
			if (i == t->len_a)
				i = 0;
		}
		while (i != 0)
		{
			rotate_pile(t, 'a');
			i--;
		}
		while (j != 0 && j > t->len_b / 2 && j < t->len_b)
		{
			rrotate_pile(t, 'b');
			j++;
			if (j == t->len_b)
				j = 0;
		}
		while (j != 0)
		{
			rotate_pile(t, 'b');
			j--;
		}
		if (i == 0)
			push_b(t);
	}
	minmax(t);
	while (t->bmax != 0)
	{
		minmax(t);
		if (t->bmax > (t->len_b / 2))
			rrotate_pile(t, 'b');
		else if (t->bmax < (t->len_b / 2) && t->bmax != 0)
			rotate_pile(t, 'b');
	}
	while (t->len_b > 0)
		push_a(t);
}
