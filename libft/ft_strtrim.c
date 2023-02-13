/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:51 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/11 16:11:59 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;

	i = 0;
	while (*s1++ == *set)
	{
		if (*(set + 1) != 0)
			set++;
	}
	while (*s1++ != *set && *(s1 + 1) == *(set + 1))
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	return (str);
}
