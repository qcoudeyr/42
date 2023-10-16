/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:30:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/16 12:10:19 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *p, long sleep)
{
	long			total;
	long			time;
	struct timeval	end;

	if (dead_check(p) == -1)
		return (-1);
	gettimeofday(&end, NULL);
	time = ft_time(p);
	pthread_mutex_lock(p->time_lock);
	time -= (((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000)) - p->last_eat;
	total = time + (sleep / 1000);
	if (total >= p->tt[0])
	{
		total = ((p->last_eat + p->tt[0]) - time);
		printf("total =%li", total);
		pthread_mutex_unlock(p->time_lock);
		usleep(time * 1000);
		execute_dead(p, ft_time(p));
		return (-1);
	}
	pthread_mutex_unlock(p->time_lock);
	usleep(sleep + 500);
	return (0);
}

long	ft_time(t_philo *p)
{
	struct timeval	end;
	long			elapsed_ms;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(p->time_lock);
	elapsed_ms = (((end.tv_sec % 1000) * 1000) + (end.tv_usec / 1000)) - \
	*p->start_time;
	pthread_mutex_unlock(p->time_lock);
	return (elapsed_ms);
}

void	m_printf(char *str, long int delay, t_philo *p)
{
	pthread_mutex_lock(p->time_lock);
	if (*p->start_time < 0)
		return ((void) pthread_mutex_unlock(p->time_lock));
	pthread_mutex_lock(p->end_lock);
	if (*p->end > 1 && p->nb_eat >= p->tt[3] && p->tt[3] != 0)
		return ((void)pthread_mutex_unlock(p->end_lock));
	pthread_mutex_unlock(p->end_lock);
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
