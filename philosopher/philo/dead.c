/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:04:44 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/16 12:37:32 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_end(t_philo *p)
{
	usleep(50000);
	pthread_mutex_lock(p->end_lock);
	if (p->alive == 1)
		*p->end += 1;
	p->alive = 0;
	while (*p->end != p->nb_ph)
	{
		pthread_mutex_unlock(p->end_lock);
		usleep(1000);
		pthread_mutex_lock(p->end_lock);
	}
	pthread_mutex_unlock(p->end_lock);
	return (0);
}

int	dead_check(t_philo *p)
{
	pthread_mutex_lock(p->end_lock);
	if (*p->end > 0 && p->nb_eat != p->tt[3])
	{
		pthread_mutex_unlock(p->end_lock);
		return (-1);
	}
	pthread_mutex_unlock(p->end_lock);
	return (0);
}

void	execute_dead(t_philo *p, long time)
{
	pthread_mutex_lock(p->end_lock);
	*p->end += 1;
	p->alive = 0;
	pthread_mutex_unlock(p->end_lock);
	pthread_mutex_lock(p->time_lock);
	if (*p->start_time > 0)
	{
		pthread_mutex_unlock(p->time_lock);
		m_printf(COLOR_RED"%li ms: %i died\n", time, p);
		pthread_mutex_lock(p->time_lock);
	}
	*p->start_time = -1;
	pthread_mutex_unlock(p->time_lock);
}

int	ft_eat_dead(t_philo *p)
{
	long			time;

	pthread_mutex_lock(p->time_lock);
	if (((p->tt[1] + p->n_philo->last_eat) >= p->last_eat + p->tt[0]) || \
	((p->tt[1] + p->p_philo->last_eat) >= p->last_eat + p->tt[0]))
	{
		time = (p->last_eat + p->tt[0]) - *p->start_time;
		pthread_mutex_unlock(p->time_lock);
		usleep(100 * p->num);
		execute_dead(p, time);
		return (-1);
	}
	pthread_mutex_unlock(p->time_lock);
	return (0);
}

int	ft_dead(t_philo *p)
{
	struct timeval	time;
	long			elapsed_ms;

	dead_check(p);
	gettimeofday(&time, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = (((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000));
	pthread_mutex_unlock(p->time_lock);
	if (elapsed_ms - p->last_eat >= p->tt[0] || \
	(p->n_philo == 0 && p->num == 1))
	{
		usleep(100 * p->num);
		execute_dead(p, ft_time(p));
		return (-1);
	}
	return (0);
}
