/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:19:03 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/02 11:33:05 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_var *var)
{
	var->n_philo = 0;
}

void	ft_readarg(int argc, char **argv, t_var *var)
{
	if (argc < 4 || argc > 7)
		printf(COLOR_RED"\nUsage = ./philo n_philo t_2_die t_2_eat\
t_2_sleep [n_times_each_philo_must_eat]\n");
	var->n_philo = argv[1];
	var->tt[0] = atoi(argv[1]);
}

int	main(int argc, char **argv)
{
	t_var	*var;

	var = malloc(sizeof(t_var) * 1);
	ft_init(var);
	ft_readarg(argc, argv, var);


	free(var);
	return (0);
}
