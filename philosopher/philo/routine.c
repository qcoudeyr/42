/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:53:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/09 09:03:12 by  qcoudeyr        ###   ########.fr       */
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
		printf("%i waited\n", p->num);
		pthread_mutex_lock(p->wait_lock);
		if (*p->wait == 0)
			wait = 0;
		pthread_mutex_unlock(p->wait_lock);

	}
	return(NULL);
}
