/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:30:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/14 16:59:12 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_end(t_philo *p)
{
	usleep(5000);
	pthread_mutex_lock(p->end_lock);
	if (p->alive == 1)
		*p->end += 1;
	p->alive = 0;
	while (*p->end != p->nb_ph)
	{
		pthread_mutex_unlock(p->end_lock);
		usleep(1000);
		pthread_mutex_lock(p->end_lock);
	}
	pthread_mutex_unlock(p->end_lock);
	return (0);
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
