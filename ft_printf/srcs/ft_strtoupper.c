/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:50:19 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/03/17 12:52:40 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strtoupper(const char *str)
{
	char	*strup;
	int		len;

	len = ft_strlen(str);
	strup = malloc(len + 1 * sizeof(char));
	while (*str != 0)
	{
		if (*str >= 97 && *str <= 122)
				*strup++ = *str -32;
		else
			*strup++ = *str;
	str++;
	}
	*strup = 0;
	return (strup - len);
}
