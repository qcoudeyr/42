/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:42:59 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/15 14:29:59 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ps_file/push_swap.h"

static int	*push(int *pile, int len, int add)
{
	int	*pile_temp;
	int	i;

	i = 0;
	pile_temp = ft_calloc(len + 1, sizeof(int));
	if (add != 0)
	{
		pile_temp[i++] = add;
		while (i < len)
		{
			pile_temp[i] = pile[i -1];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			pile_temp[i] = pile[i +1];
			i++;
		}
	}
	free(pile);
	return (pile_temp);
}

void	push_a(t_ps *t)
{
	if (t->len_b <= 0)
		return ;
	t->len_b = t->len_b - 1;
	t->len_a = t->len_a + 1;
	t->temp = push(t->pa, t->len_a, (t->pb)[0]);
	t->pa = ft_calloc(t->len_a +1, sizeof(int));
	ft_memcpy(t->pa, t->temp, t->len_a * sizeof(int));
	free(t->temp);
	t->temp = push(t->pb, t->len_b, 0);
	t->pb = ft_calloc(t->len_b +1, sizeof(int));
	ft_memcpy(t->pb, t->temp, t->len_b * sizeof(int));
	free(t->temp);
	if (t->print == 1)
		ft_printf("pa\n");
}

void	push_b(t_ps *t)
{
	if (t->len_a <= 0)
		return ;
	t->len_a = t->len_a - 1;
	t->len_b = t->len_b + 1;
	t->temp = push(t->pb, t->len_b, (t->pa)[0]);
	t->pb = ft_calloc(t->len_b +1, sizeof(int));
	ft_memcpy(t->pb, t->temp, t->len_b * sizeof(int));
	free(t->temp);
	t->temp = push(t->pa, t->len_a, 0);
	t->pa = ft_calloc(t->len_a +1, sizeof(int));
	ft_memcpy(t->pa, t->temp, t->len_a * sizeof(int));
	free(t->temp);
	if (t->print == 1)
		ft_printf("pb\n");
}

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
	t->i = 0;
	if (t->len_b >= 2)
	{
		t->bmin = 0;
		t->bmax = 0;
		while (t->i < t->len_b)
		{
			if (t->pb[t->i] > t->pb[t->bmax])
				t->bmax = t->i;
			else if (t->pb[t->i] < t->pb[t->bmin])
				t->bmin = t->i;
			t->i++;
		}
	}
}
