/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:17:28 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/14 09:05:32 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *p)
{
	
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
