/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:03:48 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/17 17:11:06 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_abs(double i)
{
	if (i < 0)
		return ((double)(i * (double)-1));
	else
		return (i);
}

unsigned long	getticks(t_cub *t)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		perror("gettimeofday failed");
		exit(EXIT_FAILURE);
	}
	if (t->init_t == 0)
	{
		t->init_t = ((tv.tv_sec * 1000UL) + tv.tv_usec / 1000UL);
		gettimeofday(&tv, NULL);
	}
	return (((tv.tv_sec * 1000UL) + (tv.tv_usec / 1000UL)) - t->init_t);
}


int	tcolor(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_data *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + \
	(y * data->line_length + x * (data->bits_per_pixel / 8))));
}
