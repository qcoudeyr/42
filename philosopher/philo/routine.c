/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/14 10:14:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_eat(t_philo *p)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	p->last_eat = ((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000);
	pthread_mutex_unlock(p->time_lock);
}

void	wait_all_philo(t_philo *p)
{
	pthread_mutex_lock(p->end_lock);
	*p->end -= 1;
	while (*p->end != 0)
	{
		pthread_mutex_unlock(p->end_lock);
		usleep(1000* 10);
		pthread_mutex_lock(p->end_lock);
	}
	pthread_mutex_unlock(p->end_lock);
	time_init(p);
	init_eat(p);
}

void	impair_routine(t_philo *p)
{
	pthread_mutex_lock(p->end_lock);
	while (*p->end == 0)
	{
		pthread_mutex_unlock(p->end_lock);
		if (ft_dead(p, 0) == -1 || ft_eat(p) == -1)
			break;
		if (ft_dead(p, 0) == -1 || ft_sleep(p) == -1)
			break;
		if (ft_dead(p, 0) == -1 || ft_thinks(p) == -1)
			break;
		pthread_mutex_lock(p->end_lock);
	}
	pthread_mutex_unlock(p->end_lock);
}

void	pair_routine(t_philo *p)
{
	pthread_mutex_lock(p->end_lock);
	while (*p->end == 0 && *p->end > p->tt[3])
	{
		pthread_mutex_unlock(p->end_lock);
		if (ft_dead(p, 0) == -1 || ft_sleep(p) == -1)
			break;
		if (ft_dead(p, 0) == -1 || ft_thinks(p) == -1)
			break;
		if (ft_dead(p, 0) == -1 || ft_eat(p) == -1)
			break;
		pthread_mutex_lock(p->end_lock);
	}
	pthread_mutex_unlock(p->end_lock);
}

void	*ft_start_routine(void *t)
{
	t_philo			*p;

	p = t;
	wait_all_philo(p);
	if (p->num % 2 == 0)
		pair_routine(p);
	else
		impair_routine(p);
	ft_end(p);
	return (NULL);
}
