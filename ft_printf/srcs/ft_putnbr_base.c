/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:38:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/04/11 12:11:46 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_negnbrbase(int len, char *digits, int sign, long n)
{
	char	*buffer;
	int		i;

	if (len > 8)
		len = 8;
	buffer = malloc (sizeof (char) * 9);
	ft_memset(buffer, digits[15], 8);
	i = 7;
	while (len-- >= 0 && i >= 0 && n != 0)
	{
		if ((n % 16) == 0 && sign == 1)
			buffer[i] = digits[0];
		else
		{
			buffer[i] = digits[(15 + sign) - (n % 16)];
			sign = 0;
		}
		n /= 16;
		i--;
	}
	write(1, buffer, 8);
	free (buffer);
	return (8);
}

static int	print_nbrbase(int len, char *digits, long n)
{
	char	*buffer;
	int		i;

	if (len > 8)
		len = 8;
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

int	ft_putnbr_base(long int n, char *base)
{
	int				len ;
	int				sign;
	long int		temp;

	len = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
		len++;
	}
	temp = n;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	if (sign < 0)
		return (print_negnbrbase(len, base, 1, temp));
	return (print_nbrbase(len, base, temp));
}
