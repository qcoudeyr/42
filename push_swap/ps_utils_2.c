/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:42:59 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/02 13:22:14 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*push(int *pile, int len, int add)
{
	int	*pile_temp;
	int	i;

	i = 0;
	pile_temp = malloc(sizeof(int) * (len + 1));
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

void	push_a(t_ps *t_ps)
{
	if (t_ps->len_b == 0)
		return ;
	t_ps->len_b = t_ps->len_b - 1;
	t_ps->len_a = t_ps->len_a + 1;
	t_ps->temp = malloc(sizeof(int) * t_ps->len_a);
	t_ps->temp = push(t_ps->pa, t_ps->len_a, (t_ps->pb)[0]);
	t_ps->pa = malloc(sizeof(int) * t_ps->len_a +1);
	ft_memcpy(t_ps->pa, t_ps->temp, t_ps->len_a * sizeof(int));
	free(t_ps->temp);
	t_ps->temp = malloc(sizeof(int) * t_ps->len_b +1);
	t_ps->temp = push(t_ps->pb, t_ps->len_b, 0);
	t_ps->pb = malloc(sizeof(int) * t_ps->len_b +1);
	ft_memcpy(t_ps->pb, t_ps->temp, t_ps->len_b * sizeof(int));
	free(t_ps->temp);
	ft_printf("pa\n");
}

void	push_b(t_ps *t_ps)
{
	if (t_ps->len_a <= 0)
		return ;
	t_ps->len_a = t_ps->len_a - 1;
	t_ps->len_b = t_ps->len_b + 1;
	t_ps->temp = malloc((t_ps->len_b +1) * sizeof(int));
	if (!t_ps->temp)
		ft_exit(t_ps, 1);
	t_ps->temp = push(t_ps->pb, t_ps->len_b, (t_ps->pa)[0]);
	t_ps->pb = malloc(sizeof(int) * t_ps->len_b +1);
	ft_memcpy(t_ps->pb, t_ps->temp, t_ps->len_b * sizeof(int));
	free(t_ps->temp);
	t_ps->temp = malloc(sizeof(int) * t_ps->len_a +1);
	t_ps->temp = push(t_ps->pa, t_ps->len_a, 0);
	t_ps->pa = malloc(sizeof(int) * t_ps->len_a +1);
	ft_memcpy(t_ps->pa, t_ps->temp, t_ps->len_a * sizeof(int));
	free(t_ps->temp);
	ft_printf("pb\n");
}
