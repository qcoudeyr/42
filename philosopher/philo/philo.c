/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:19:03 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/12 14:26:26 by  qcoudeyr        ###   ########.fr       */
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
	var->n_philo = ft_atoi(argv[1]);
	var->tt[0] = ft_atoi(argv[2]);
	var->tt[1] = ft_atoi(argv[3]);
	var->tt[2] = ft_atoi(argv[4]);
	var->tt[3] = 0;
	if (argc == 6)
		var->tt[3] = ft_atoi(argv[5]);
	if (var->n_philo < 1 || var->tt[0] < 1 || var->tt[1] < 1 || \
	var->tt[2] < 1 || (var->tt[3] < 1 && argc == 6))
	{
		printf(COLOR_RED"Args invalid !\nPlease enter number >= 1");
		ft_free(var);
		exit(EXIT_FAILURE);
	}
}

void	wait_dead(t_var *var)
{
	pthread_mutex_lock(&var->dead_lock);
	while (var->dead != 1)
	{
		pthread_mutex_unlock(&var->dead_lock);
		pthread_mutex_lock(&var->eat_lock);
		if (var->n_eat_f == var->n_philo)
			var->n_eat_f = -1;
		pthread_mutex_unlock(&var->eat_lock);
		usleep(100000);
		pthread_mutex_lock(&var->dead_lock);
	}
	pthread_mutex_unlock(&var->dead_lock);
}

void	mutex_free(t_var *var)
{
	pthread_mutex_destroy(&var->lock);
	pthread_mutex_destroy(&var->eat_lock);
	pthread_mutex_destroy(&var->time_lock);
	pthread_mutex_destroy(&var->dead_lock);
}

void	ft_free(t_var *var)
{
	t_philo	*temp;
	t_philo	*philo;
	int		i;

	i = 0;
	temp = NULL;
	philo = var->f_philo;
	while (i < var->n_philo)
	{
		if (philo->n_philo)
			temp = philo->n_philo;
		else
			temp = NULL;
		pthread_mutex_destroy(&philo->fork_lock);
		pthread_join(philo->tid, NULL);
		philo->num = 0;
		philo->n_philo = NULL;
		philo->p_philo = NULL;
		free(philo);
		philo = temp;
		i++;
	}
	mutex_free(var);
	free(var);
	var = NULL;
}

int	main(int argc, char **argv)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	var->n_philo = 0;
	var->p = NULL;
	var->wait = 1;
	var->start_time = 0;
	var->n_eat_f = 0;
	var->dead = 0;
	pthread_mutex_init(&var->lock, NULL);
	pthread_mutex_init(&var->eat_lock, NULL);
	pthread_mutex_init(&var->time_lock, NULL);
	pthread_mutex_init(&var->dead_lock, NULL);
	ft_readarg(argc, argv, var);
	init_philo(var);
	ft_free(var);
	return (0);
}
