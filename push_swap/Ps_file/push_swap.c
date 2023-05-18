/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:46:26 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/15 14:30:06 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ps_file/push_swap.h"

int	main(int argc, char **argv)
{
	struct t_ps	t_ps;

	t_ps.print = 1;
	if (ft_error(argc, argv) == 1)
		return (write(2, "Error\n", 6));
	else if (argc == 2)
		ft_init_1_args(argv, &t_ps);
	else if (argc > 2)
		ft_init(argc, argv, &t_ps);
	if (!t_ps.pa)
		return (write(2, "Error\n", 7));
	if (ft_issort(&t_ps) == 1)
		ft_exit(&t_ps, 0);
	ft_sort(&t_ps);
	ft_exit(&t_ps, 0);
	return (0);
}
