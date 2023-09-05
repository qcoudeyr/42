/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:19:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/05 13:58:21 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arg_checker(int argc, char **argv)
{
	void	*ptr;

	if (argc != 2)
		return (0);
	ptr = ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]));
	if (ptr == argv[1] || ptr == NULL)
		return (0);
	return (1);
}
