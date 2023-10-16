/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:07:20 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/16 08:09:27 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_free(t_var *var)
{
	pthread_mutex_destroy(&var->end_lock);
	pthread_mutex_destroy(&var->time_lock);
	pthread_mutex_destroy(&var->print_lock);
}

void	free_philo(t_var *var)
{
	t_philo	*temp;
	t_philo	*philo;
	int		i;

	i = 0;
	temp = NULL;
	philo = var->f_philo;
	while (i < var->nb_philo)
	{
		if (philo->n_philo)
			temp = philo->n_philo;
		else
			temp = NULL;
		pthread_mutex_destroy(&philo->fork_lock);
		philo->n_philo = NULL;
		philo->p_philo = NULL;
		free(philo);
		philo = temp;
		i++;
	}
}

void	ft_free(t_var *var)
{
	if (var->p != NULL)
	{
		join_philo(var);
		free_philo(var);
	}
	mutex_free(var);
	free(var);
	var = NULL;
}
