/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:19:14 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/05 12:51:21 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	random_color(void)
{
	int	red = 255;
	int	green = 255;
	int	blue = 255;

	int color = (red << 16) | (green << 8) | blue;

	return color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	background(t_mlx lib, t_data *data)
{
	for(int x = 0;x < 1280;x++)
	{
		for(int y = 0; y < 800; y++)
			my_mlx_pixel_put(data, x, y, random_color());
	}
	mlx_put_image_to_window(lib.mlx, lib.current_win, data->img, 0, 0);
}

void	addpoint(t_mlx lib, t_data *data)
{
	int color = (255 << 16);
	for(int x = 0;x < 1280;x += 10)
	{
		for(int y = 0; y < 800; y += 10)
			my_mlx_pixel_put(data, x, y, color);
	}
	mlx_put_image_to_window(lib.mlx, lib.current_win, data->img, 0, 0);
}


