/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:19:03 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/09 13:28:11 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_readarg(int argc, char **argv, t_var *var)
{
	if (argc < 4 || argc > 7)
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
void	init_time(pthread_mutex_t	time_lock, long *time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);

	pthread_mutex_lock(&time_lock);
	*time = start.tv_usec;
	pthread_mutex_unlock(&time_lock);
}

void	init_philo(t_var *var)
{
	int		i;
	void	*p_philo;

	i = 0;
	p_philo = NULL;
	var->f_philo = NULL;
	while (i < var->n_philo)
	{
		i++;
		var->p = malloc(sizeof(t_philo));
		if (i == 1)
			var->f_philo = var->p;
		var->p->n_philo = NULL;
		var->p->tt[0] = var->tt[0];
		var->p->tt[1] = var->tt[1];
		var->p->tt[2] = var->tt[2];
		var->p->tt[3] = var->tt[3];
		var->p->tof = 0;
		var->p->last_eat = 0;
		pthread_mutex_init(&var->p->fork_lock, NULL);
		var->p->num = i;
		var->p->wait_lock = &var->lock;
		var->p->time_lock = &var->time_lock;
		pthread_mutex_lock(&var->lock);
		var->p->start_time = &var->start_time;
		pthread_mutex_unlock(&var->lock);
		pthread_mutex_lock(&var->lock);
		var->p->wait = &var->wait;
		pthread_mutex_unlock(&var->lock);
		var->p->state = ALIVE;
		var->p->p_philo = p_philo;
		if (var->p->p_philo != NULL)
			var->p->p_philo->n_philo = var->p;
		var->p->fork = 1;
		if (i == var->n_philo)
			var->p->n_philo = var->f_philo;
		p_philo = var->p;
		pthread_create(&var->p->tid, NULL, ft_start_routine, var->p);
	}
	pthread_mutex_lock(&var->lock);
	var->wait = 0;
	init_time(var->time_lock, &var->start_time);
	pthread_mutex_unlock(&var->lock);
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
	pthread_mutex_destroy(&var->lock);
	pthread_mutex_destroy(&var->time_lock);
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
	pthread_mutex_init(&var->lock, NULL);
	pthread_mutex_init(&var->time_lock, NULL);
	ft_readarg(argc, argv, var);
	init_philo(var);
	ft_free(var);
	return (0);
}
