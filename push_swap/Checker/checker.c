/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:27:40 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/15 16:37:31 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ps_file/push_swap.h"

int	do_line(t_ps *t, char *line)
{
	if (!(ft_strcmp(line, "sa\n")))
		swap_pile(t, 'a');
	else if (!(ft_strcmp(line, "sb\n")))
		swap_pile(t, 'b');
	else if (!(ft_strcmp(line, "ss\n")))
		swap_pile(t, 's');
	else if (!(ft_strcmp(line, "pa\n")))
		push_a(t);
	else if (!(ft_strcmp(line, "pb\n")))
		push_b(t);
	else if (!(ft_strcmp(line, "ra\n")))
		rotate_pile(t, 'a');
	else if (!(ft_strcmp(line, "rb\n")))
		rotate_pile(t, 'b');
	else if (!(ft_strcmp(line, "rr\n")))
		rotate_pile(t, 'r');
	else if (!(ft_strcmp(line, "rra\n")))
		rrotate_pile(t, 'a');
	else if (!(ft_strcmp(line, "rrb\n")))
		rrotate_pile(t, 'b');
	else if (!(ft_strcmp(line, "rrr\n")))
		rrotate_pile(t, 'r');
	else
		return (0);
	return (1);
}

void	read_op(t_ps *t)
{
	char		*line;

	line = get_next_line(0);
	while (line)
	{
		if (!do_line(t, line))
		{
			free(line);
			get_next_line(-1);
			ft_exit(t, 1);
		}
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	struct t_ps	t_ps;

	t_ps.print = 0;
	if (ft_error(argc, argv) < 0)
		return (write(2, "Error\n", 6));
	if (argc == 2)
		ft_init_1_args(argv, &t_ps);
	else if (argc > 2)
		ft_init(argc, argv, &t_ps);
	if (!t_ps.pa)
		return (write(2, "Error!\n", 7));
	read_op(&t_ps);
	if (ft_issort(&t_ps) == 1 && t_ps.len_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_exit(&t_ps, 0);
	return (0);
}
