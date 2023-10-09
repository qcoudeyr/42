/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/09 10:35:38 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_start_routine(t_philo *p)
{
	int				wait;

	wait = 1;
	printf("%i joined the table\n", p->num);
	while (wait == 1)
	{
		usleep(10000 * p->num);
		pthread_mutex_lock(p->wait_lock);
		if (*p->wait == 0)
			wait = 0;
		pthread_mutex_unlock(p->wait_lock);
	}
	pthread_mutex_lock(p->time_lock);
	printf("%i philo itime = %li\n", p->num, *p->itime);
	pthread_mutex_unlock(p->time_lock);

	return(NULL);
}

long	ft_time(t_philo *p)
{
	struct timeval	end;
	long			elapsed_usec;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_usec = (end.tv_sec - *p->itime) * 1000000 + (end.tv_usec - *p->itime);
	pthread_mutex_unlock(p->time_lock);
	return (elapsed_usec);
}

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(&p->fork_lock);
	printf("%li ms: %i has taken a fork", ft_time(p), p->num);
	pthread_mutex_lock(&p->n_philo->fork_lock);
	printf("%li ms: %i has taken a fork", ft_time(p), p->num);
	usleep(p->tt[1] * 1000000);
	pthread_mutex_lock(&p->fork_lock);
	pthread_mutex_lock(&p->n_philo->fork_lock);
}




