/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:19:03 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/16 09:59:55 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_readarg(int argc, char **argv, t_var *var)
{
	if (argc < 5 || argc > 7)
	{
		printf(COLOR_RED"\nUsage = ./philo n_philo t_2_die t_2_eat\
t_2_sleep [n_times_each_philo_must_eat]\n");
		ft_free(var);
		exit(EXIT_FAILURE);
	}
	var->nb_philo = ft_atoi(argv[1]);
	var->tt[0] = ft_atoi(argv[2]);
	var->tt[1] = ft_atoi(argv[3]);
	var->tt[2] = ft_atoi(argv[4]);
	var->tt[3] = 0;
	if (argc == 6)
		var->tt[3] = ft_atoi(argv[5]);
	if (var->nb_philo < 1 || var->tt[0] < 60 || var->tt[1] < 60 || \
	var->tt[2] < 60 || (var->tt[3] < 1 && argc == 6))
	{
		printf(COLOR_RED"Args invalid !\nPlease enter number of philo >= 1 \
or a time2die, time2eat, time2sleep >= 60 ms\n");
		ft_free(var);
		exit(EXIT_FAILURE);
	}
}

void	wait_dead(t_var *var)
{
	pthread_mutex_lock(&var->end_lock);
	while (var->end != var->nb_philo)
	{
		pthread_mutex_unlock(&var->end_lock);
		usleep(100000);
		pthread_mutex_lock(&var->end_lock);
	}
	pthread_mutex_unlock(&var->end_lock);
}

int	main(int argc, char **argv)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	var->nb_philo = 0;
	var->p = NULL;
	var->start_time = 0;
	var->end = 0;
	pthread_mutex_init(&var->end_lock, NULL);
	pthread_mutex_init(&var->time_lock, NULL);
	pthread_mutex_init(&var->print_lock, NULL);
	ft_readarg(argc, argv, var);
	init_philo(var);
	ft_free(var);
	return (0);
}
