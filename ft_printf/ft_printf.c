/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:49:28 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/02/27 13:05:19 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	char	**str;

	str = ft_split(string, '%');
	while (*str)
	{
		ft_putstr_fd(*str++, 1);
		ft_putstr_fd("\n", 1);
	}
	return (ft_strlen(string));
}

int	main(void)
{
	ft_printf("Ceci est le premier test %s prem%dier %cseule");
	return (0);
}
