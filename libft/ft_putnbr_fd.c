/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcoudeyr <qcoudeyr@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:52:03 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/07 14:54:36 by qcoudeyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbm;

	nbm = n;
	if (n < 0)
	{
		ft_putchar_fd(45, fd);
		nbm *= -1;
	}
	if (nbm < 10)
	{
		ft_putchar_fd(nbm + 48, fd);
		return ;
	}
	else
		ft_putnbr_fd(nbm / 10, fd);
	ft_putnbr_fd(nbm % 10, fd);
}
