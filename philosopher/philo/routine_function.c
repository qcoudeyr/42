/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:17:28 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/13 20:50:44 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_unlock_order(t_philo *p)
{

	pthread_mutex_lock(p->eat_lock);
	if (p->num < p->n_philo->num)
	{
		if (p->n_philo->f_lock == 1)
		{
			p->n_philo->f_lock = 0;
			pthread_mutex_unlock(&p->n_philo->fork_lock);
		}
		if (p->f_lock == 1)
		{
			p->f_lock = 0;
			pthread_mutex_unlock(&p->fork_lock);
		}
	}
	else
	{
		if (p->f_lock == 1 && p->n_philo->f_lock == 1)
		{
			p->f_lock = 0;
			pthread_mutex_unlock(&p->fork_lock);
		}
		if (p->n_philo->f_lock == 1)
		{
			p->n_philo->f_lock = 0;
			pthread_mutex_unlock(&p->n_philo->fork_lock);
		}
	}
	pthread_mutex_unlock(p->eat_lock);
	printf("num = %i, fork= %i\n", p->num, p->f_lock);
}

void	mutex_lock_order(t_philo *p)
{
	printf("num = %i, fork= %i\n", p->num, p->f_lock);
	if (p->num < p->n_philo->num)
	{
		pthread_mutex_lock(&p->n_philo->fork_lock);
		p->n_philo->f_lock = 1;
		pthread_mutex_lock(&p->fork_lock);
		p->f_lock = 1;
	}
	else
	{
		pthread_mutex_lock(&p->fork_lock);
		p->f_lock = 1;
		pthread_mutex_lock(&p->n_philo->fork_lock);
		p->n_philo->f_lock = 1;
	}
}

int	ft_eat(t_philo *p)
{
	struct timeval	time;
	long int		delay;
	int				num;

	if (dead_check(p, 1) == -1 || ft_eat_dead(p) == -1)
		return (-1);

	mutex_lock_order(p);

	if (ft_dead(p, 1) == -1)
		return (-1);

	gettimeofday(&time, NULL);
	delay = ft_time(p);
	num = p->num;

	m_printf(COLOR_YELLOW"%li ms: %i has taken a fork\n", delay, num, p);
	m_printf(COLOR_YELLOW"%li ms: %i has taken a fork\n", delay, num, p);

	pthread_mutex_lock(p->eat_lock);
	p->last_eat = ((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000);
	pthread_mutex_unlock(p->eat_lock);

	m_printf(COLOR_GREEN"%li ms: %i is eating\n", delay, num, p);

	num = ft_usleep(p, p->tt[1] * 1000, 1);

	mutex_unlock_order(p);

	p->n_eat++;
	if (p->n_eat == p->tt[3] && p->tt[3] != 0)
		return (ft_eat_end(p));
	return(num);
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
