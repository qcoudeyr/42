/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:21:15 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/15 14:29:55 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ps_file/push_swap.h"

void	swap_pile(t_ps *t, char c)
{
	int	temp;

	if (!t->pa || !t->pb)
		return ;
	if (((!t->pa[0] || !t->pa[1]) && (c == 'a' || c == 's')) || ((!t->pb[0] \
	|| !t->pb[1]) && (c == 'b' || c == 's')))
		return ;
	if (c == 'a' || c == 's')
	{
		temp = t->pa[0];
		t->pa[0] = t->pa[1];
		t->pa[1] = temp;
	}
	if (c == 'b' || c == 's')
	{
		temp = t->pb[0];
		t->pb[0] = t->pb[1];
		t->pb[1] = temp;
	}
	if (t->print == 1)
		ft_printf("s%c\n", c);
	return ;
}

static void	rotate(int *pile, int i, char c)
{
	int	temp;
	int	temp2;
	int	len;

	if (c == 'r')
	{
		len = 0;
		temp = pile[len];
		pile[len++] = pile[i];
		while (len <= i)
		{
			temp2 = pile[len];
			pile[len++] = temp;
			temp = temp2;
		}
		return ;
	}
	temp = pile[i];
	pile[i--] = pile[0];
	while (i >= 0)
	{
		temp2 = pile[i];
		pile[i--] = temp;
		temp = temp2;
	}
}

void	rotate_pile(t_ps *t, char c)
{
	if (((!t->pa[0]) && (c == 'a' || c == 'r')) || (!t->pb[0] \
	&& (c == 'b' || c == 'r')))
		return ;
	if (c == 'a' || c == 'r')
		rotate(t->pa, (t->len_a - 1), 0);
	if (c == 'b' || c == 'r')
		rotate(t->pb, (t->len_b - 1), 0);
	if (t->print == 1)
		ft_printf("r%c\n", c);
	return ;
}

void	rrotate_pile(t_ps *t, char c)
{
	if (((!t->pa[0]) && (c == 'a' || c == 'r')) || (!t->pb[0] \
	&& (c == 'b' || c == 'r')))
		return ;
	if (c == 'a' || c == 'r')
		rotate(t->pa, (t->len_a - 1), 'r');
	if (c == 'b' || c == 'r')
		rotate(t->pb, (t->len_b - 1), 'r');
	if (t->print == 1)
		ft_printf("rr%c\n", c);
	return ;
}
