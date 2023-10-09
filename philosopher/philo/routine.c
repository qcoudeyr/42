/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/09 08:41:36 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_start_routine(t_philo *p)
{
	pthread_mutex_t	lock;
	int				wait;

	wait = 1;
	pthread_mutex_init(&lock, NULL);
	printf("%i joined the table\n", p->num);
	while (wait == 1)
	{
		usleep(10000 * p->num);
		printf("%i waited\n", p->num);
		pthread_mutex_lock(&lock);
		if (*p->wait == 0)
			wait = 0;
		pthread_mutex_unlock(&lock);
	}
	pthread_mutex_destroy(&lock);
	return(NULL);
}
