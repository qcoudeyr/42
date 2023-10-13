/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:17:28 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/13 08:56:02 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_end(t_philo *p)
{
	pthread_mutex_lock(p->eat_lock);
	*p->n_eat_f += 1;
	while (*p->n_eat_f != -1)
	{
		pthread_mutex_unlock(p->eat_lock);
		usleep(1000000);
		pthread_mutex_lock(p->eat_lock);
	}
	pthread_mutex_unlock(p->eat_lock);
	return (-1);
}

void	mutex_unlock_order(t_philo *p)
{
	if (p->num < p->n_philo->num)
	{
		if (p->nf_lock == 1)
		{
			pthread_mutex_unlock(&p->n_philo->fork_lock);
			p->nf_lock = 0;
		}
		if (p->f_lock == 1)
		{
			pthread_mutex_unlock(&p->fork_lock);
			p->f_lock = 0;
		}
	}
	else
	{
		if (p->f_lock == 1)
		{
			pthread_mutex_unlock(&p->fork_lock);
			p->f_lock = 0;
		}
		if (p->nf_lock == 1)
		{
			pthread_mutex_unlock(&p->n_philo->fork_lock);
			p->nf_lock = 0;
		}
	}
}

void	mutex_lock_order(t_philo *p)
{
	if (p->num < p->n_philo->num)
	{
		pthread_mutex_lock(&p->n_philo->fork_lock);
		p->nf_lock = 1;
		pthread_mutex_lock(&p->fork_lock);
		p->f_lock = 1;
	}
	else
	{
		pthread_mutex_lock(&p->fork_lock);
		p->f_lock = 1;
		pthread_mutex_lock(&p->n_philo->fork_lock);
		p->nf_lock = 1;
	}
}

void	ft_eat(t_philo *p)
{
	struct timeval	time;
	long int		delay;
	int				num;

	dead_check(p, 1);
	ft_eat_dead(p);
	mutex_lock_order(p);
	ft_dead(p, 1);
	gettimeofday(&time, NULL);
	delay = ft_time(p, 1);
	num = p->num;
	printf(COLOR_YELLOW"%li ms: %i has taken a fork\n%li ms: \
%i has taken a fork\n", delay, num, delay, num);
	pthread_mutex_lock(p->eat_lock);
	p->last_eat = ((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000);
	pthread_mutex_unlock(p->eat_lock);
	printf(COLOR_GREEN"%li ms: %i is eating\n", delay, num);
	ft_usleep(p, p->tt[1] * 1000, 1);
	p->n_eat++;
	if (p->n_eat == p->tt[3] && p->tt[3] != 0)
		ft_eat_end(p);
}

void	ft_sleep(t_philo *p)
{
	long int	delay;
	int			num;

	dead_check(p, 0);
	delay = ft_time(p, 0);
	num = p->num;
	printf(COLOR_BLUE"%li ms: %i is sleeping\n", delay, num);
	ft_usleep(p, p->tt[2] * 1000, 0);
}

void	ft_thinks(t_philo *p)
{
	long int	delay;
	int			num;

	dead_check(p, 0);
	delay = ft_time(p, 0);
	num = p->num;
	printf(COLOR_BLACK"%li ms: %i is thinking\n", delay, num);
}
