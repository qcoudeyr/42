/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/13 16:32:43 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *p, long sleep, int routine_n)
{
	struct timeval	time;
	long			total;

	if (dead_check(p, routine_n) == -1)
		return (-1);
	gettimeofday(&time, NULL);
	total = ((((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000)) \
	+ (sleep / 1000));
	pthread_mutex_lock(p->eat_lock);
	if ((total - p->last_eat) >= p->tt[0])
	{
		if (routine_n == 1)
			mutex_unlock_order(p);
		p->state = DEAD;
		pthread_mutex_lock(p->dead_lock);
		if (*p->is_dead == 0)
			*p->is_dead = 1;
		else
			return (pthread_mutex_unlock(p->dead_lock) - 1);
		pthread_mutex_unlock(p->dead_lock);
		pthread_mutex_lock(p->time_lock);
		m_printf(COLOR_RED"%li ms: %i died 3\n", ((p->last_eat + p->tt[0]) \
		- *p->start_time), p->num, p);
		pthread_mutex_unlock(p->eat_lock);
		pthread_mutex_unlock(p->time_lock);
		usleep(10000);
		return (-1);
	}
	pthread_mutex_unlock(p->eat_lock);
	usleep(sleep);
	return (0);
}

long int	ft_time(t_philo *p)
{
	struct timeval	end;
	long int		elapsed_ms;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	if (*p->start_time == 0)
		*p->start_time = ((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000);
	elapsed_ms = (((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000)) - \
	*p->start_time;
	pthread_mutex_unlock(p->time_lock);
	return (elapsed_ms);
}

void	init_eat(t_philo *p)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->eat_lock);
	p->last_eat = ((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000);
	pthread_mutex_unlock(p->eat_lock);
}

void	start_wait(t_philo *p, int wait)
{
	while (wait == 1)
	{
		usleep(10000);
		pthread_mutex_lock(p->wait_lock);
		if (*p->wait == 0)
			wait = 0;
		pthread_mutex_unlock(p->wait_lock);
	}
}

void	*ft_start_routine(void *t)
{
	t_philo			*p;


	p = t;
	start_wait(p, 1);
	time_init(p);
	init_eat(p);
	if (p->num % 2 == 1)
		{
			ft_sleep(p);
			ft_thinks(p);
			ft_dead(p, 0);
		}
	while (p->state == ALIVE)
	{
		if (ft_dead(p, 0) == -1 || ft_eat(p) == -1)
			break;
		if (ft_dead(p, 0) == -1 || ft_sleep(p) == -1)
			break;
		if (ft_dead(p, 0) == -1 || ft_thinks(p) == -1)
			break;
	}
	ft_end(p);
	return (NULL);
}
