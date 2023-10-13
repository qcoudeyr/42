/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:18:56 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/13 20:26:35 by  qcoudeyr        ###   ########.fr       */
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
	pthread_mutex_unlock(p->time_lock);
}

void	var_mutex_init(t_var *var)
{
	pthread_mutex_init(&var->p->fork_lock, NULL);
	var->p->wait_lock = &var->lock;
	var->p->end_lock = &var->end_lock;
	var->p->print_lock = &var->print_lock;
	var->p->time_lock = &var->time_lock;
	var->p->dead_lock = &var->dead_lock;
	pthread_mutex_lock(&var->end_lock);
	var->p->n_end_f = &var->n_end_f;
	pthread_mutex_unlock(&var->end_lock);
	pthread_mutex_lock(&var->lock);
	var->p->start_time = &var->start_time;
	pthread_mutex_unlock(&var->lock);
	pthread_mutex_lock(&var->lock);
	var->p->wait = &var->wait;
	pthread_mutex_unlock(&var->lock);
	var->p->eat_lock = &var->eat_lock;
	pthread_mutex_lock(&var->eat_lock);
	var->p->n_eat_f = &var->n_eat_f;
	pthread_mutex_unlock(&var->eat_lock);
}

void	var_philo_init(t_var *var, int i, void *p_philo)
{
	var->p->n_philo = NULL;
	var->p->tt[0] = var->tt[0];
	var->p->tt[1] = var->tt[1];
	var->p->tt[2] = var->tt[2];
	var->p->tt[3] = var->tt[3];
	var->p->tof = 0;
	var->p->tt_ph = var->n_philo;
	var->p->f_lock = 0;
	var->p->nf_lock = 0;
	var->p->last_eat = 0;
	var->p->n_eat = 0;
	var->p->is_dead = &var->dead;
	var->p->num = i;
	var_mutex_init(var);
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
		if (i == var->n_philo && var->p != var->f_philo)
			var->p->n_philo = var->f_philo;
		p_philo = var->p;
		pthread_create(&var->p->tid, NULL, ft_start_routine, var->p);
	}
	pthread_mutex_lock(&var->lock);
	var->wait = 0;
	pthread_mutex_unlock(&var->lock);
	wait_dead(var);
}
