/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/20 11:05:12 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_eat(t_philo *p)
{
	long			delay;
	struct timeval	time;

	gettimeofday(&time, NULL);
	m_printf(COLOR_YELLOW"%li ms: %i has taken a fork\n", -1, p);
	m_printf(COLOR_YELLOW"%li ms: %i has taken a fork\n", -1, p);
	m_printf(COLOR_GREEN"%li ms: %i is eating\n", -1, p);
	pthread_mutex_lock(p->time_lock);
	p->last_eat = (time.tv_sec * 1000000 + time.tv_usec);
	pthread_mutex_unlock(p->time_lock);
	delay = ft_usleep(p, (p->tt[1] * 1000));
	eat_mutex_unlock(p);
	return ((int) delay);
}

void	wait_all_philo(t_philo *p)
{
	pthread_mutex_lock(p->end_lock);
	*p->end -= 1;
	while (*p->end < 0)
	{
		pthread_mutex_unlock(p->end_lock);
		usleep(1000);
		pthread_mutex_lock(p->end_lock);
	}
	pthread_mutex_unlock(p->end_lock);
	time_init(p);
}

void	impair_routine(t_philo *p)
{
	int	lock;

	lock = 1;
	usleep(100);
	pthread_mutex_lock(p->end_lock);
	while (*p->end == 0)
	{
		pthread_mutex_unlock(p->end_lock);
		lock = 0;
		if (ft_dead(p) == -1 || ft_eat(p) == -1)
			break ;
		if (ft_dead(p) == -1 || ft_sleep(p) == -1)
			break ;
		if (ft_dead(p) == -1 || ft_thinks(p) == -1)
			break ;
		pthread_mutex_lock(p->end_lock);
		lock = 1;
	}
	if (lock == 1)
		pthread_mutex_unlock(p->end_lock);
}

void	pair_routine(t_philo *p)
{
	int	lock;

	lock = 1;
	usleep(100);
	pthread_mutex_lock(p->end_lock);
	while (*p->end == 0)
	{
		pthread_mutex_unlock(p->end_lock);
		lock = 0;
		if (ft_dead(p) == -1 || ft_sleep(p) == -1)
			break ;
		if (ft_dead(p) == -1 || ft_thinks(p) == -1)
			break ;
		if (ft_dead(p) == -1 || ft_eat(p) == -1)
			break ;
		pthread_mutex_lock(p->end_lock);
		lock = 1;
	}
	if (lock == 1)
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
