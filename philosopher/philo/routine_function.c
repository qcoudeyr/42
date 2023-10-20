/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:17:28 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/20 10:38:38 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_mutex_unlock(t_philo *p)
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
}

void	eat_mutex_lock(t_philo *p)
{
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
}

int	ft_eat(t_philo *p)
{
	int	val;

	usleep(1000);
	if (ft_dead(p) == -1 || ft_eat_dead(p) == -1)
		return (-1);
	eat_mutex_lock(p);
	val = print_eat(p);
	if (ft_dead(p) == -1)
		return (-1);
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
	usleep(100);
	return (val);
}

int	ft_sleep(t_philo *p)
{
	int			i;

	usleep(1000);
	if (ft_dead(p) == -1)
		return (-1);
	m_printf(COLOR_BLUE"%li ms: %i is sleeping\n", -1, p);
	i = ft_usleep(p, (p->tt[2] * 1000));
	usleep(100);
	return (i);
}

int	ft_thinks(t_philo *p)
{
	usleep(1000);
	if (ft_dead(p) == -1)
		return (-1);
	m_printf(COLOR_BLACK"%li ms: %i is thinking\n", -1, p);
	return (0);
}
