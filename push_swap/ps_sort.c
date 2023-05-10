/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:40:44 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/10 12:08:27 by  qcoudeyr        ###   ########.fr       */
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
/*
static int	pos_vmax(t_ps *t)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (i < t->len_b)
	{
		if (t->pb[temp] < t->pb[i])
			temp = i;
		i++;
	}
	return (temp);
} */

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
	while (ft_issort(t) != 1 && t->len_a > 1)
	{
		tab[2] = 100;
		minmax(t);
		while (i < t->len_a)
		{
			if (t->pa[i] < t->pb[t->bmin])
				j = t->bmin + 1;
			else
			{
				while (t->pa[i] > t->pb[j] && j < t->len_b)
					j++;
				if (t->pa[i] > t->pb[t->bmax])
					j = t->bmax;
				while (t->pa[i] < t->pb[j] && j < t->len_b)
					j++;
			}
			sum = i;
			sum += j;
			if (sum < tab[2])
			{
				tab[0] = i;
				tab[1] = j;
				tab[2] = sum;
			}
			i++;
		}
		i = tab[0];
		j = tab[1];
		while (i != 0 && j != 0)
		{
			rotate_pile(t, 'r');
			i--;
			j--;
		}
		while (i != 0)
		{
			rotate_pile(t, 'a');
			i--;
		}
		while (j != 0 && j != t->len_b)
		{
			rotate_pile(t, 'b');
			j--;
		}
		if (j == t->len_b)
		{
			push_b(t);
			rotate_pile(t, 'b');
			j = 0;
		}
		else
			push_b(t);
	}
}
/* {
	int	size;

	size = t->len_a;
	t->i = 0;
	while (ft_issort(t) == 0 && t->i < t->len_a)
	{
		t->j = 1;
		while (t->j < size + 1)
		{
			if (((t->pa[0] >> t->i) & 1) == 1)
				rotate_pile(t, 'a');
			else if (ft_issort(t) == 1)
				break ;
			else
				push_b(t);
			t->j++;
		}
		while (t->len_b > 0)
			push_a(t);
		t->i++;
	}
}

 */
