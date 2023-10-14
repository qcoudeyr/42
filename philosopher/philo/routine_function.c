/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:17:28 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/14 15:24:20 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *p, long sleep)
{
	struct timeval	time;
	long			total;

	if (dead_check(p) == -1)
		return (-1);
	gettimeofday(&time, NULL);
	pthread_mutex_lock(p->time_lock);
	total = ((((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000)) \
	+ (sleep / 1000));
	pthread_mutex_unlock(p->time_lock);
	if (total - p->last_eat >= p->tt[0])
	{
		usleep((total - p->tt[0]) *1000);
		execute_dead(p, ft_time(p));
		return (-1);
	}
	usleep(sleep + 500);
	return (0);
}

long	ft_time(t_philo *p)
{
	struct timeval	end;
	long		elapsed_ms;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = (((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000)) - \
	*p->start_time;
	pthread_mutex_unlock(p->time_lock);
	return (elapsed_ms);
}

int	ft_eat(t_philo *p)
{
	struct timeval	time;
	long			delay;

	if (ft_dead(p) == -1 || ft_eat_dead(p) == -1)
		return (-1);
	if (p->num > p->n_philo->num)
	{
		pthread_mutex_lock(&p->n_philo->fork_lock);
		p->n_philo->fork = 0;
		pthread_mutex_lock(&p->fork_lock);
		p->n_philo->fork = 0;
	}
	else
	{
		pthread_mutex_lock(&p->fork_lock);
		p->n_philo->fork = 0;
		pthread_mutex_lock(&p->n_philo->fork_lock);
		p->n_philo->fork = 0;
	}
	if (ft_dead(p) == -1 || ft_eat_dead(p) == -1)
	{
		if (p->num > p->n_philo->num)
		{
			pthread_mutex_unlock(&p->n_philo->fork_lock);
			p->n_philo->fork = 1;
			pthread_mutex_unlock(&p->fork_lock);
			p->n_philo->fork = 1;
		}
		else
		{
			pthread_mutex_unlock(&p->fork_lock);
			p->n_philo->fork = 1;
			pthread_mutex_unlock(&p->n_philo->fork_lock);
			p->n_philo->fork = 1;
		}
		return (-1);
	}
	gettimeofday(&time, NULL);
	delay = ft_time(p);

	m_printf(COLOR_YELLOW"%li ms: %i has taken a fork\n", delay, p);
	m_printf(COLOR_YELLOW"%li ms: %i has taken a fork\n", delay, p);

	pthread_mutex_lock(p->time_lock);
	p->last_eat = ((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000);
	pthread_mutex_unlock(p->time_lock);

	m_printf(COLOR_GREEN"%li ms: %i is eating\n", delay, p);

	delay = ft_usleep(p, p->tt[1] * 1000);

	if (p->num > p->n_philo->num)
	{
		pthread_mutex_unlock(&p->n_philo->fork_lock);
		p->n_philo->fork = 1;
		pthread_mutex_unlock(&p->fork_lock);
		p->n_philo->fork = 1;
	}
	else
	{
		pthread_mutex_unlock(&p->fork_lock);
		p->n_philo->fork = 1;
		pthread_mutex_unlock(&p->n_philo->fork_lock);
		p->n_philo->fork = 1;
	}
	p->nb_eat++;
	if (p->nb_eat == p->tt[3] && p->tt[3] != 0)
	{
		usleep(10000);
		pthread_mutex_lock(p->end_lock);
		*p->end += 1;
		p->alive = 0;
		pthread_mutex_unlock(p->end_lock);
		return (-1);
	}
	return(delay);

}

int	ft_sleep(t_philo *p)
{
	long int	delay;
	int			i;

	if (ft_dead(p) == -1)
		return (-1);
	delay = ft_time(p);
	m_printf(COLOR_BLUE"%li ms: %i is sleeping\n", delay, p);
	i = ft_usleep(p, p->tt[2] * 1000);
	return (i);
}

int	ft_thinks(t_philo *p)
{
	long int	delay;

	if (ft_dead(p) == -1)
		return (-1);
	delay = ft_time(p);
	m_printf(COLOR_BLACK"%li ms: %i is thinking\n", delay, p);
	return (0);
}
