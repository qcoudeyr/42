/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:54:46 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/04/25 11:23:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>

typedef struct t_ps
{
	char	**temp_split;
	int		*pa;
	int		*pb;
	int		*index;
	int		len_a;
	int		len_b;
	int		vmin;
	int		vmax;
	int		i;
	int		j;
	int		pos;
}	t_ps;

void	swap_pile(int *pile_a, int *pile_b, char c);
void	push_a(t_ps *t_ps);
void	push_b(t_ps *t_ps);
void	rotate_pile(int *pile_a, int *pile_b, char c, int len);
void	rrotate_pile(int *pile_a, int *pile_b, char c, int len);

#endif
