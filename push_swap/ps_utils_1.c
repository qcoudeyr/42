/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:21:15 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/04/24 12:43:26 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_pile(int *pile_a, int *pile_b, char c)
{
	int	temp;

	if (((!pile_a[0] || !pile_a[1]) && (c == 'a' || c == 's')) || ((!pile_b[0] \
	|| !pile_b[1]) && (c == 'b' || c == 's')))
		return ;
	if (c == 'a' || c == 's')
	{
		temp = pile_a[0];
		pile_a[0] = pile_a[1];
		pile_a[1] = temp;
	}
	if (c == 'b' || c == 's')
	{
		temp = pile_b[0];
		pile_b[0] = pile_b[1];
		pile_b[1] = temp;
	}
	printf("s%c\n", c);
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
	while (i > 0)
	{
		temp2 = pile[i];
		pile[i--] = temp;
		temp = temp2;
	}
}

void	rotate_pile(int *pile_a, int *pile_b, char c, int len)
{
	if (((!pile_a[0]) && (c == 'a' || c == 'r')) || (!pile_b[0] \
	&& (c == 'b' || c == 'r')))
		return ;
	if (c == 'a' || c == 'r')
		rotate(pile_a, (len - 1), 0);
	if (c == 'b' || c == 'r')
		rotate(pile_b, (len - 1), 0);
	printf("r%c\n", c);
	return ;
}

void	rrotate_pile(int *pile_a, int *pile_b, char c, int len)
{
	if (((!pile_a[0]) && (c == 'a' || c == 'r')) || (!pile_b[0] \
	&& (c == 'b' || c == 'r')))
		return ;
	if (c == 'a' || c == 'r')
		rotate(pile_a, (len - 1), 'r');
	if (c == 'b' || c == 'r')
		rotate(pile_b, (len - 1), 'r');
	printf("rr%c\n", c);
	return ;
}
