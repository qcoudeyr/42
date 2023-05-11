/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:54:46 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/11 12:01:56 by  qcoudeyr        ###   ########.fr       */
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
	int		bmin;
	int		bmax;
	int		i;
	int		j;
	int		pos;
	int		p_a;
	int		p_b;
	int		best[3];
	int		sum;
}	t_ps;

void	ft_init(int argc, char **argv, t_ps *t);
void	ft_init_1_args(char **argv, t_ps *t);
void	ft_indexer(t_ps *t);

void	swap_pile(t_ps *t, char c);
void	push_a(t_ps *t_ps);
void	push_b(t_ps *t_ps);
void	rotate_pile(t_ps *t, char c);
void	rrotate_pile(t_ps *t, char c);

void	ft_sort(t_ps *t);
void	sort_array(t_ps *t);
void	sort_small(t_ps *t);
void	sort_small_5(t_ps *t);

void	compare_op(t_ps *t);
void	set_min_push(t_ps *t);
void	do_op_on_a(t_ps *t);
void	do_op_on_b(t_ps *t);
void	finish_sort(t_ps *t);

int		ft_issort(t_ps *t);
int		ft_isrevsort(int *arr, int len);

void	minmax(t_ps *t);

void	ft_exit(t_ps *t, int v);
void	free_temp(t_ps *t);

#endif
