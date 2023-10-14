/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:04:44 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/14 10:55:06 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *p)
{
	pthread_mutex_lock(p->end_lock);
	if (*p->end > 0)
	{
		pthread_mutex_unlock(p->end_lock);
		return(-1);
	}
	pthread_mutex_unlock(p->end_lock);
	return (0);
}

int	ft_eat_dead(t_philo *p)
{
	struct timeval	end;
	long			time;

	pthread_mutex_lock(p->time_lock);

	if (((p->tt[1] + p->n_philo->last_eat) > p->last_eat + p->tt[0]))
	{
		time = (p->tt[1] + p->n_philo->last_eat) - (p->last_eat + p->tt[0]);
		pthread_mutex_unlock(p->time_lock);
		usleep(time * 1000);
		pthread_mutex_lock(p->end_lock);
		*p->end += 1;
		pthread_mutex_unlock(p->end_lock);
		gettimeofday(&end, NULL);
		pthread_mutex_lock(p->time_lock);
		m_printf(COLOR_RED"%li ms: %i died eat_dead\n", ((p->last_eat + p->tt[0]) \
		- *p->start_time), p);
		pthread_mutex_unlock(p->time_lock);
		return (-1);
	}
	pthread_mutex_unlock(p->time_lock);
	return (0);
}

int	ft_dead(t_philo *p)
{
	struct timeval	end;
	long int		elapsed_ms;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = ((((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000)) \
	- p->last_eat);
	pthread_mutex_unlock(p->time_lock);
	if (elapsed_ms >= p->tt[0] || (p->n_philo == NULL && p->num == 1))
	{
		pthread_mutex_lock(p->end_lock);
		*p->end += 1;
		pthread_mutex_unlock(p->end_lock);
		pthread_mutex_lock(p->time_lock);
		m_printf(COLOR_RED"%li ms: %i died ft_dead\n", ((((end.tv_sec % 1000) * 1000) \
	+ (end.tv_usec / 1000)) - *p->start_time), p);
		pthread_mutex_unlock(p->time_lock);
		return (-1);
	}
	return (0);
}
