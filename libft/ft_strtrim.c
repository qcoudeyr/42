/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:51 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/13 23:39:46 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	while (ft_strrchr(set, s1[i]) != NULL)
		i++;
	while (ft_strrchr(set, s1[j]) != NULL)
		j--;
	str = malloc(sizeof (char) * (j - i) + 2);
	if (!str)
		return (malloc(1));
	ft_strlcpy(str, &s1[i], (j - i + 2));
	return (str);
}
