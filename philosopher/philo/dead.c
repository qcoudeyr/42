/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:04:44 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/14 14:18:08 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *p)
{
	pthread_mutex_lock(p->end_lock);
	if (*p->end > 0 && p->nb_eat != p->tt[3])
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
	if (((p->tt[1] + p->n_philo->last_eat) >= p->last_eat + p->tt[0]))
	{
		time = (p->last_eat + p->tt[0]) - *p->start_time;
		pthread_mutex_unlock(p->time_lock);
		usleep(time * 1000);
		pthread_mutex_lock(p->end_lock);
		*p->end += 1;
		pthread_mutex_unlock(p->end_lock);
		p->alive = 0;
		gettimeofday(&end, NULL);
		pthread_mutex_lock(p->time_lock);
		if (*p->start_time > 0 && pthread_mutex_unlock(p->time_lock))
			m_printf(COLOR_RED"%li ms: %i died eat_dead\n", time, p);
		*p->start_time = -1;
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

	dead_check(p);
	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = ((((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000));
	pthread_mutex_unlock(p->time_lock);
	if (elapsed_ms - p->last_eat >= p->tt[0] || (p->n_philo == 0 && p->num == 1))
	{
		pthread_mutex_lock(p->end_lock);
		*p->end += 1;
		p->alive = 0;
		pthread_mutex_unlock(p->end_lock);
		pthread_mutex_lock(p->time_lock);
		elapsed_ms -= *p->start_time;
		if (*p->start_time > 0 && pthread_mutex_unlock(p->time_lock))
			m_printf(COLOR_RED"%li ms: %i died ft_dead\n", elapsed_ms, p);
		pthread_mutex_lock(p->time_lock);
		*p->start_time = -1;
		pthread_mutex_unlock(p->time_lock);
		return (-1);
	}
	return (0);
}
