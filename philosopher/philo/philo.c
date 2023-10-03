/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:19:03 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/03 10:30:51 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_var *var)
{
	var->n_philo = 0;
}

void	ft_readarg(int argc, char **argv, t_var *var)
{
	if (argc < 4 || argc > 7)
		printf(COLOR_RED"\nUsage = ./philo n_philo t_2_die t_2_eat\
t_2_sleep [n_times_each_philo_must_eat]\n");
	var->n_philo = ft_atoi(argv[1]);
	var->tt[0] = ft_atoi(argv[2]);
	var->tt[1] = ft_atoi(argv[3]);
	var->tt[2] = ft_atoi(argv[4]);
	if (argc == 6)
		var->tt[3] = ft_atoi(argv[5]);
	if (var->n_philo < 1 || var->tt[0] < 1 || var->tt[1] < 1 || \
	var->tt[2] < 1 || var->tt[3] < 1)
	{
		printf(COLOR_RED"Args invalid !\nPlease enter number >= 1");
		ft_free(var);
		exit(EXIT_FAILURE);
	}
}

void	init_philo(t_var *var, t_philo *philo)
{
	int	i;

	i = 0;
	while(i < var->n_philo)
	{
		i++;

	}

}

void	ft_free(t_var *var)
{
	free(var);
	var = NULL;
}

int	main(int argc, char **argv)
{
	t_var	*var;
	t_philo	*philo;

	var = malloc(sizeof(t_var) * 1);
	ft_init(var);
	ft_readarg(argc, argv, var);
	philo = malloc(sizeof(t_philo) * var->n_philo);
	
	free(var);
	return (0);
}
