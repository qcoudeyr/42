/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/09 17:41:56 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long int	ft_time(t_philo *p)
{
	struct timeval	end;
	long int		elapsed_ms;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = (end.tv_usec - *p->start_time) / 1000;
	pthread_mutex_unlock(p->time_lock);
	return (elapsed_ms);
}




void	*ft_start_routine(t_philo *p)
{
	int				wait;

	wait = 1;
	printf("%i joined the table\n", p->num);
	while (wait == 1)
	{
		usleep(10000);
		pthread_mutex_lock(p->wait_lock);
		if (*p->wait == 0)
			wait = 0;
		pthread_mutex_unlock(p->wait_lock);
	}
	if (p->num % 2 == 0)
		usleep(100);
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

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&p->fork_lock);
	pthread_mutex_lock(&p->n_philo->fork_lock);
	printf("%li ms: %i has taken a fork\n", ft_time(p), p->num);
	printf("%li ms: %i has taken a fork\n", ft_time(p), p->num);
	usleep(p->tt[1] * 1000);
	pthread_mutex_unlock(&p->n_philo->fork_lock);
	pthread_mutex_unlock(&p->fork_lock);

	p->last_eat = time.tv_usec;
	return(NULL);
}

void	ft_sleep(t_philo *p)
{
	printf("%li ms: %i is sleeping\n", ft_time(p), p->num);
	usleep(p->tt[2] * 1000);
}

void	ft_thinks(t_philo *p)
{
	printf("%li ms: %i is thinking\n", ft_time(p), p->num);
}

void	ft_dead(t_philo *p)
{
	struct timeval	end;
	long int		elapsed_ms;

	gettimeofday(&end, NULL);
	elapsed_ms = (end.tv_usec - p->last_eat) / 1000;
	if (elapsed_ms >= p->tt[0])
	{
		p->state = DEAD;
		pthread_mutex_lock(p->dead_lock);
		*p->is_dead = 1;
		pthread_mutex_unlock(p->dead_lock);
		pthread_mutex_lock(p->time_lock);
		printf("%li ms: %i died\n", ((end.tv_usec - *p->start_time) / 1000), p->num);
		pthread_mutex_unlock(p->time_lock);
		exit(0);
	}
}
