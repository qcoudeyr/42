/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/10 10:10:25 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long int	ft_time(t_philo *p)
{
	struct timeval	end;
	long int		elapsed_ms;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = (((end.tv_sec % 100) * 1000) + (end.tv_usec / 1000)) - *p->start_time;
;
	pthread_mutex_unlock(p->time_lock);
	return (elapsed_ms);
}




void	*ft_start_routine(t_philo *p)
{
	int				wait;

	wait = 1;
	while (wait == 1)
	{
		usleep(10000);
		pthread_mutex_lock(p->wait_lock);
		if (*p->wait == 0)
			wait = 0;
		pthread_mutex_unlock(p->wait_lock);
	}
	if (p->num % 2 == 0)
		ft_sleep(p);
	while (p->state == ALIVE)
	{
		ft_eat(p);
		ft_dead(p);
		ft_sleep(p);
		ft_dead(p);
		ft_thinks(p);
		ft_dead(p);
	}
	return(NULL);
}

void	*ft_eat(t_philo *p)
{
	struct timeval	time;

	pthread_mutex_lock(&p->fork_lock);
	pthread_mutex_lock(&p->n_philo->fork_lock);
	printf(COLOR_YELLOW"%li ms: %i has taken a fork\n", ft_time(p), p->num);
	printf(COLOR_YELLOW"%li ms: %i has taken a fork\n", ft_time(p), p->num);
	printf(COLOR_GREEN"%li ms: %i is eating\n", ft_time(p), p->num);
	usleep(p->tt[1] * 1000);
	pthread_mutex_unlock(&p->n_philo->fork_lock);
	pthread_mutex_unlock(&p->fork_lock);
	gettimeofday(&time, NULL);
	p->last_eat = ((time.tv_sec % 100) * 1000) + (time.tv_usec / 1000);
	return(NULL);
}

void	ft_sleep(t_philo *p)
{
	printf(COLOR_BLUE"%li ms: %i is sleeping\n", ft_time(p), p->num);
	usleep(p->tt[2] * 1000);
}

void	ft_thinks(t_philo *p)
{
	printf(COLOR_BLACK"%li ms: %i is thinking\n", ft_time(p), p->num);
}

void	ft_dead(t_philo *p)
{
	struct timeval	end;
	long int		elapsed_ms;

	gettimeofday(&end, NULL);
	elapsed_ms = (((end.tv_sec % 100) * 1000) + (end.tv_usec / 1000) - p->last_eat);
	if (elapsed_ms >= p->tt[0])
	{
		p->state = DEAD;
		pthread_mutex_lock(p->dead_lock);
		*p->is_dead = 1;
		pthread_mutex_unlock(p->dead_lock);
		pthread_mutex_lock(p->time_lock);
		printf(COLOR_RED"%li ms: %i died\n", ((((end.tv_sec % 100) * 1000) + (end.tv_usec / 1000)) - *p->start_time), p->num);
		pthread_mutex_unlock(p->time_lock);
		exit(0);
	}
}
