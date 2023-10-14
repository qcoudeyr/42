/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/14 16:58:32 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_philo(t_philo *p)
{
	pthread_mutex_lock(p->end_lock);
	*p->end -= 1;
	while (*p->end != 0)
	{
		pthread_mutex_unlock(p->end_lock);
		usleep(1000 * 10);
		pthread_mutex_lock(p->end_lock);
	}
	pthread_mutex_unlock(p->end_lock);
	time_init(p);
}

void	impair_routine(t_philo *p)
{
	int	lock;

	lock = 1;
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
