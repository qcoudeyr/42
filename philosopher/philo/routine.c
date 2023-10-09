/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/09 11:34:17 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long int	ft_time(t_philo *p)
{
	struct timeval	end;
	long int		elapsed_ms;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = (end.tv_usec - *p->itime) / 1000;
	
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
	p->last_eat = ft_time(p);
	while (p->state == ALIVE)
	{
		ft_eat(p);
		ft_sleep(p);
		ft_thinks(p);
	}


	return(NULL);
}

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(&p->fork_lock);
	printf("%li ms: %i has taken a fork", ft_time(p), p->num);
	pthread_mutex_lock(&p->n_philo->fork_lock);
	printf("%li ms: %i has taken a fork", ft_time(p), p->num);
	usleep(p->tt[1] * 1000);
	pthread_mutex_lock(&p->fork_lock);
	pthread_mutex_lock(&p->n_philo->fork_lock);
	p->last_eat = 0;
}

void	ft_sleep(t_philo *p)
{
	printf("%li ms: %i is sleeping", ft_time(p), p->num);
	usleep(p->tt[2] * 1000);
	p->last_eat += p->tt[2];
	pthread_mutex_lock(&p->fork_lock);
	pthread_mutex_lock(&p->n_philo->fork_lock);
}

void	ft_thinks(t_philo *p)
{
	printf("%li ms: %i is thinking", ft_time(p), p->num);
	pthread_mutex_lock(&p->fork_lock);
	pthread_mutex_lock(&p->n_philo->fork_lock);
}


