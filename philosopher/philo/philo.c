/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:19:03 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/02 11:18:11 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_var *var)
{
	var = malloc(sizeof(t_var) * 1);
	var->n_philo = 0;
}

void	ft_readarg(int argv, char **argc, t_var *var)
{

}

int	main(int argc, char **argv)
{
	t_var	*var;

	ft_init(var);
	ft_readarg(argv, );


}
