/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:54:46 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/02 14:24:58 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <limits.h>

typedef struct t_ps
{
	char	**temp_split;
	int		*pa;
	int		*pb;
	int		*index;
	int		*temp;
	int		len_a;
	int		len_b;
	int		vmin;
	int		vmax;
	int		i;
	int		j;
	int		pos;
	int		pivot;
}	t_ps;

void	swap_pile(t_ps *t, char c);
void	push_a(t_ps *t_ps);
void	push_b(t_ps *t_ps);
void	rotate_pile(t_ps *t, char c);
void	rrotate_pile(t_ps *t, char c);
void	ft_sort(t_ps *t);
void	sort_array(t_ps *t);
int		ft_issort(t_ps *t);
int		ft_isrevsort(int *arr, int len);
void	minmax(t_ps *t, int *arr);
void	ft_exit(t_ps *t, int v);
#endif
