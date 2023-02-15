/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:47 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/15 13:36:58 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordlen(const char *s, char chr)
{
	int	c;

	c = 0;
	while (*s != 0 && *s != chr)
	{
		c++;
		s++;
	}
	return (c);
}

static int	ft_wordct(const char *s, char chr)
{
	int	c;
	int	index;

	c = 0;
	index = 0;
	while (s[index] != 0)
	{
		while (s[index] == chr && s[index] != 0)
			index++;
		if (s[index] != chr && s[index] != 0)
			c++;
		while (s[index] != chr && s[index] != 0)
			index++;
	}
	return (c);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		index;
	char	**tab;
	char	*s;

	s = ft_strtrim (str, &c);
	i = 0;
	index = 0;
	if (!*s)
	{
		tab = malloc(sizeof(char *) * 1);
		tab[0] = malloc(sizeof(char) * 1);
		tab[0] = 0;
		return (tab);
	}
	tab = (char **)malloc(sizeof(char *) * ft_wordct(s, c) + 1);
	while (s[i] || (s[i] == c && s[i+1] == 0))
	{
		while (s[i] == c && s[i] != 0)
			i++;
		tab[index] = malloc(sizeof(char) * ft_wordlen(&s[i], c) + 1);
		ft_strlcpy(tab[index++], &s[i], ft_wordlen(&s[i], c) + 1);
		i += ft_wordlen(&s[i], c);
	}
	tab[index] = NULL;
	return (tab);
}
