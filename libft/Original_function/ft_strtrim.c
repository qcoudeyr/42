/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:51 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/05/09 10:53:08 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	while (ft_strrchr(set, s1[i]) != NULL && i <= j)
		i++;
	while (ft_strrchr(set, s1[j]) != NULL && i <= j)
		j--;
	str = malloc(sizeof (char) * (j - i) + 2);
	if (!str)
		return (malloc(0));
	ft_strlcpy(str, &s1[i], (j - i + 2));
	return (str);
}
