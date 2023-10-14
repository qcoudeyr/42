/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:17:28 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/14 10:10:54 by  qcoudeyr        ###   ########.fr       */
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
	pthread_mutex_lock(p->time_lock);
	total = ((((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000)) \
	+ (sleep / 1000)) - p->last_eat;
	pthread_mutex_unlock(p->time_lock);
	if (total >= p->tt[0])
	{
		usleep((total - p->tt[0]) *1000);
		pthread_mutex_lock(p->end_lock);
		*p->end += 1;
		pthread_mutex_unlock(p->end_lock);
		pthread_mutex_lock(p->time_lock);
		gettimeofday(&time, NULL);
		m_printf(COLOR_RED"%li ms: %i died 1\n", ((((time.tv_sec % 1000) * 1000) \
	+ (time.tv_usec / 1000)) - *p->start_time), p->num, p);
		pthread_mutex_unlock(p->time_lock);
		return (-1);
	}
	pthread_mutex_unlock(p->time_lock);
	usleep(sleep);
	return (0);
}

long int	ft_time(t_philo *p)
{
	struct timeval	end;
	long int		elapsed_ms;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = (((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000)) - \
	*p->start_time;
	pthread_mutex_unlock(p->time_lock);
	return (elapsed_ms);
}

int	ft_eat(t_philo *p)
{

}

int	ft_sleep(t_philo *p)
{
	long int	delay;
	int			num;
	int			i;

	if (dead_check(p, 0) == -1)
		return (-1);
	delay = ft_time(p);
	num = p->num;
	m_printf(COLOR_BLUE"%li ms: %i is sleeping\n", delay, num, p);
	i = ft_usleep(p, p->tt[2] * 1000, 0);
	return (i);
}

int	ft_thinks(t_philo *p)
{
	long int	delay;
	int			num;

	if (dead_check(p, 0) == -1)
		return (-1);
	delay = ft_time(p);
	num = p->num;
	m_printf(COLOR_BLACK"%li ms: %i is thinking\n", delay, num, p);
	return (0);
}
