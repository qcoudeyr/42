/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pttostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:17:21 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/03/28 15:25:07 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	prt_negnb(int len, char *digits, int sign, long long unsigned int n)
{
	char	*buffer;
	int		i;

	if (len > 8)
		len = 16;
	buffer = malloc (sizeof (char) * len +1);
	ft_memset(buffer, digits[15], len);
	i = len -1;
	while (i >= 0 && n != 0)
	{
		if ((n % 16) == 0)
			buffer[i] = digits[0];
		else
		{
			buffer[i] = digits[(15 + sign) - (n % 16)];
			sign = 0;
		}
		n /= 16;
		i--;
	}
	write(1, buffer, len);
	free (buffer);
	return (len);
}

static int	print_nbrbase(int len, char *digits, long n)
{
	char	*buffer;
	int		i;

	if (len > 8)
		len = 16;
	buffer = malloc (sizeof(char) * len +1);
	buffer[len] = 0;
	i = len - 1;
	while (i >= 0 && n != 0)
	{
		buffer[i] = digits[(n % 16)];
		n /= 16;
		i--;
	}
	write(1, buffer, len);
	free (buffer);
	return (len);
}

static int	putpt_base(long long int n, char *base)
{
	int							len ;
	int							sign;
	long long unsigned int		temp;

	len = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		temp = -n;
		len++;
	}
	temp = n;
	if (temp == 0)
		return (write(1, "0", 1));
	while (temp > 0)
	{
		len++;
		temp /= 16;
	}
	temp = n * sign;
	if (sign < 0)
		return (prt_negnb(len, base, 1, temp));
	return (print_nbrbase(len, base, temp));
}

int	ft_pttostr(void *n)
{
	if (n == NULL)
		return (ft_putstr_fd("(nil)", 1));
	return (ft_putstr_fd("0x", 1) + \
	putpt_base((long)n, "0123456789abcdef"));
}
