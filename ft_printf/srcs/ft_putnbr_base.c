/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:38:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/04/14 12:53:17 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_nbrbase(int len, char *digits, unsigned long long n)
{
	char	*buffer;
	int		i;

	buffer = malloc (sizeof(char) * len +1);
	buffer[len] = 0;
	i = len - 1;
	while (i >= 0)
	{
		buffer[i] = digits[(n % 16)];
		n /= 16;
		i--;
	}
	write(1, buffer, len);
	free (buffer);
	return (len);
}

int	ft_putnbr_base(unsigned long long n, char *base)
{
	int						len ;
	unsigned long long		temp;

	len = 0;
	temp = n;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (print_nbrbase(len, base, temp));
}
