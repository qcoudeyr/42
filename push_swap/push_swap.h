/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:54:46 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/10 11:31:21 by  qcoudeyr        ###   ########.fr       */
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
int		ft_issort(t_ps *t);
int		ft_isrevsort(int *arr, int len);
void	minmax(t_ps *t);
void	ft_exit(t_ps *t, int v);
void	sort_small(t_ps *t);
void	sort_small_5(t_ps *t);
void	free_temp(t_ps *t);
#endif
