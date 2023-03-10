/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:53 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/27 12:24:42 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (*s != 0)
	{
		c++;
		s++;
	}
	return (c);
}
