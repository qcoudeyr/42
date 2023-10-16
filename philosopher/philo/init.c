/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:18:56 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/16 10:33:34 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_init(t_philo *p)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	if (*p->start_time == 0)
		*p->start_time = ((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000);
	p->last_eat = *p->start_time;
	pthread_mutex_unlock(p->time_lock);
}

void	var_mutex_init(t_var *var)
{
	pthread_mutex_init(&var->p->fork_lock, NULL);
	var->p->end_lock = &var->end_lock;
	var->p->print_lock = &var->print_lock;
	var->p->time_lock = &var->time_lock;
	pthread_mutex_lock(&var->time_lock);
	var->p->start_time = &var->start_time;
	pthread_mutex_unlock(&var->time_lock);
}

void	var_philo_init(t_var *var, int i, void *p_philo)
{
	var->p->n_philo = NULL;
	var->p->tt[0] = var->tt[0];
	var->p->tt[1] = var->tt[1];
	var->p->tt[2] = var->tt[2];
	var->p->tt[3] = var->tt[3];
	var->p->alive = 1;
	var->p->nb_ph = var->nb_philo;
	var->p->last_eat = 0;
	var->p->nb_eat = 0;
	var->p->end = &var->end;
	var->p->num = i;
	var->p->fork = 1;
	var->p->p_philo = p_philo;
	if (var->p->p_philo != NULL)
		var->p->p_philo->n_philo = var->p;
	if (var->nb_philo == i && var->f_philo != NULL)
		var->f_philo->p_philo = var->p;
	var_mutex_init(var);
}

void	unlock_philo(t_var *var)
{
	pthread_mutex_lock(&var->end_lock);
	while (var->end != (-1 * var->nb_philo))
	{
		pthread_mutex_unlock(&var->end_lock);
		usleep(1000);
		pthread_mutex_lock(&var->end_lock);
	}
	var->end = 0;
	pthread_mutex_unlock(&var->end_lock);
}

void	init_philo(t_var *var)
{
	int		i;
	void	*p_philo;

	i = 0;
	p_philo = NULL;
	var->f_philo = NULL;
	while (i < var->nb_philo)
	{
		i++;
		var->p = malloc(sizeof(t_philo));
		if (i == 1)
			var->f_philo = var->p;
		var_philo_init(var, i, p_philo);
		if (i == var->nb_philo && var->p != var->f_philo)
			var->p->n_philo = var->f_philo;
		p_philo = var->p;
		pthread_create(&var->p->tid, NULL, ft_start_routine, var->p);
	}
	unlock_philo(var);
	wait_dead(var);
}
