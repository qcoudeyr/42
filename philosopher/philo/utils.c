/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:30:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/20 10:33:10 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *p, long sleep)
{
	long			total;
	long			delay;
	struct timeval	time;

	if (dead_check(p) == -1)
		return (-1);
	gettimeofday(&time, NULL);
	delay = (time.tv_sec * 1000000 + time.tv_usec) / 1000;
	pthread_mutex_lock(p->time_lock);
	total = (delay - p->last_eat) + (sleep / 1000);
	if (total > p->tt[0])
	{
		delay = p->last_eat - *p->start_time;
		pthread_mutex_unlock(p->time_lock);
		total = (ft_time(p) - (delay));
		if (total < 10)
			total = p->tt[0];
		usleep(total * 1000);
		execute_dead(p, ft_time(p));
		return (-1);
	}
	pthread_mutex_unlock(p->time_lock);
	usleep(sleep);
	return (0);
}

long int	ft_time(t_philo *p)
{
	struct timeval	time;
	long int		elapsed_ms;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = ((time.tv_sec * 1000000) + time.tv_usec) / 1000;
	elapsed_ms -= *p->start_time;
	pthread_mutex_unlock(p->time_lock);
	return (elapsed_ms);
}

void	m_printf(char *str, long int delay, t_philo *p)
{
	pthread_mutex_lock(p->end_lock);
	if (*p->end > 1 && p->nb_eat >= p->tt[3] && p->tt[3] != 0)
	{
		pthread_mutex_unlock(p->end_lock);
		return ;
	}
	pthread_mutex_unlock(p->end_lock);
	if (delay == -1)
		delay = ft_time(p);
	pthread_mutex_lock(p->time_lock);
	if (*p->start_time < 0)
	{
		pthread_mutex_unlock(p->time_lock);
		return ;
	}
	pthread_mutex_lock(p->print_lock);
	printf(str, delay, p->num);
	pthread_mutex_unlock(p->print_lock);
	pthread_mutex_unlock(p->time_lock);
}

static int	ft_isspace(const char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

long int	ft_atoi(const char *str)
{
	long long int	value;
	int				neg;

	value = 0;
	neg = 1;
	while (ft_isspace(*(char *)str) == 1)
		str++;
	if (*(char *)str == '-')
	{
		neg *= -1;
		str++;
	}
	else if (*(char *)str == '+')
		str++;
	while (*(unsigned char *)str < 58 && *(unsigned char *)str > 47)
		value = (value * 10 + (*str++ - 48));
	return (value * neg);
}
