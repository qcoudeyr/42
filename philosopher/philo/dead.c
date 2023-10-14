/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:04:44 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/14 10:11:43 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *p, int routine_n)
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

	pthread_mutex_lock(p->eat_lock);

	if (((p->tt[1] + p->n_philo->last_eat) > p->last_eat + p->tt[0]))
	{
		time = (p->tt[1] + p->n_philo->last_eat) - (p->last_eat + p->tt[0]);
		pthread_mutex_unlock(p->eat_lock);
		usleep(time * 1000);
		p->state = DEAD;
		pthread_mutex_lock(p->dead_lock);
		if (*p->is_dead == 0)
			*p->is_dead = 1;
		else
			return (pthread_mutex_unlock(p->dead_lock) - 1);
		pthread_mutex_unlock(p->nmn);
		pthread_mutex_lock(p->time_lock);
		gettimeofday(&end, NULL);
		pthread_mutex_lock(p->eat_lock);
		m_printf(COLOR_RED"%li ms: %i died 2\n", ((p->last_eat + p->tt[0]) \
		- *p->start_time), p->num, p);
		pthread_mutex_unlock(p->eat_lock);
		pthread_mutex_unlock(p->time_lock);
		return (-1);
	}
	pthread_mutex_unlock(p->eat_lock);
	return (0);
}

int	ft_dead(t_philo *p, int routine_n)
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
		m_printf(COLOR_RED"%li ms: %i died 1\n", ((((end.tv_sec % 1000) * 1000) \
	+ (end.tv_usec / 1000)) - *p->start_time), p->num, p);
		pthread_mutex_unlock(p->time_lock);
		return (-1);
	}
	return (0);
}