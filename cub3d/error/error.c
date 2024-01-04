/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:38:04 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/04 10:14:09 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	printerr(char *str)
{
	ft_printf(CL_RED BOLD"%s"RESET, str);
	return (-1);
}

int	printerrf(char *str, void *ptr)
{
	if (ptr != NULL)
		ptr = pfree(ptr);
	ft_printf(CL_RED BOLD"%s"RESET, str);
	return (-1);
}
