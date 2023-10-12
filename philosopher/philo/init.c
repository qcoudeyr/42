/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:18:56 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/12 07:19:35 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_time(pthread_mutex_t	time_lock, long *time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	pthread_mutex_lock(&time_lock);
	*time = ((start.tv_sec % 1000) * 1000) + (start.tv_usec / 1000);
	pthread_mutex_unlock(&time_lock);
}

void	var_philo_init(t_var *var, int i, void *p_philo)
{
	var->p->n_philo = NULL;
	var->p->tt[0] = var->tt[0];
	var->p->tt[1] = var->tt[1];
	var->p->tt[2] = var->tt[2];
	var->p->tt[3] = var->tt[3];
	var->p->tof = 0;
	var->p->last_eat = 0;
	var->p->is_dead = &var->dead;
	pthread_mutex_init(&var->p->fork_lock, NULL);
	var->p->num = i;
	var->p->wait_lock = &var->lock;
	var->p->time_lock = &var->time_lock;
	var->p->dead_lock = &var->dead_lock;
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
		var_philo_init(var, i, p_philo);
		if (i == var->n_philo)
			var->p->n_philo = var->f_philo;
		p_philo = var->p;
		pthread_create(&var->p->tid, NULL, ft_start_routine, var->p);
	}
	pthread_mutex_lock(&var->lock);
	var->wait = 0;
	pthread_mutex_unlock(&var->lock);
	wait_dead(var);
}
