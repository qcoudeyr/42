/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:17:28 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/12 10:20:00 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_eat(t_philo *p)
{
	struct timeval	time;

	pthread_mutex_lock(p->dead_lock);
	if (*p->is_dead == 1)
		exit(0);
	pthread_mutex_unlock(p->dead_lock);
	pthread_mutex_lock(&p->fork_lock);
	pthread_mutex_lock(&p->n_philo->fork_lock);
	printf(COLOR_YELLOW"%li ms: %i has taken a fork\n%li ms: \
%i has taken a fork\n", ft_time(p), p->num, ft_time(p), p->num);
	gettimeofday(&time, NULL);
	p->last_eat = ((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000);
	printf(COLOR_GREEN"%li ms: %i is eating\n", ft_time(p), p->num);
	ft_usleep(p, p->tt[1] * 1000);
	pthread_mutex_unlock(&p->n_philo->fork_lock);
	pthread_mutex_unlock(&p->fork_lock);
	p->n_eat++;
	if (p->n_eat == p->tt[3] && p->tt[3] != 0)
	{
		pthread_mutex_lock(p->eat_lock);
		*p->n_eat_f += 1;
		while (*p->n_eat_f != -1)
		{
			pthread_mutex_unlock(p->eat_lock);
			usleep(1000000);
			pthread_mutex_lock(p->eat_lock);
		}
		exit(1);
	}
	return (NULL);
}

void	ft_sleep(t_philo *p)
{
	pthread_mutex_lock(p->dead_lock);
	if (*p->is_dead == 1)
	{
		pthread_mutex_unlock(p->dead_lock);
		exit(0);
	}
	pthread_mutex_unlock(p->dead_lock);
	printf(COLOR_BLUE"%li ms: %i is sleeping\n", ft_time(p), p->num);
	ft_usleep(p, p->tt[2] * 1000);
}

void	ft_thinks(t_philo *p)
{
	pthread_mutex_lock(p->dead_lock);
	if (*p->is_dead == 1)
	{
		pthread_mutex_unlock(p->dead_lock);
		exit(0);
	}
	pthread_mutex_unlock(p->dead_lock);
	printf(COLOR_BLACK"%li ms: %i is thinking\n", ft_time(p), p->num);
}

void	ft_dead(t_philo *p)
{
	struct timeval	end;
	long int		elapsed_ms;

	gettimeofday(&end, NULL);
	elapsed_ms = ((((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000)) - p->last_eat);
	if (elapsed_ms >= p->tt[0] || (p->n_philo == NULL && p->num == 1))
	{
		p->state = DEAD;
		pthread_mutex_lock(p->dead_lock);
		*p->is_dead = 1;
		pthread_mutex_unlock(p->dead_lock);
		pthread_mutex_lock(p->time_lock);
		printf(COLOR_RED"%li ms: %i died\n", ((((end.tv_sec % 1000) * 1000) \
	+ (end.tv_usec / 1000)) - *p->start_time), p->num);
		pthread_mutex_unlock(p->time_lock);
		exit(0);
	}
}
