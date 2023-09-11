/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:21:36 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/11 12:43:12 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	background(t_mlx *lib, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < lib->sizex)
	{
		y = 0;
		while (y < lib->sizey)
		{
			my_mlx_pixel_put(data, x, y, tcolor(255, 255, 255));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(lib->mlx, lib->current_win, data->img, 0, 0);
}

void	addmap(t_mlx *lib, t_data *data)
{
	t_map	*line;

	line = lib->map->first;
	while (lib->map != NULL)
	{
		while (lib->map != NULL)
		{
			if (lib->map->nx != NULL)
				line_put(lib, lib->map, lib->map->nx, data);
			if (lib->map->ny != NULL)
				line_put(lib, lib->map, lib->map->ny, data);
			lib->map = lib->map->nx;
		}
		lib->map = line->ny;
		line = line->ny;
	}
	mlx_put_image_to_window(lib->mlx, lib->current_win, data->img, 0, 0);
	lib->map = lib->map_origin;
}

int	tcolor(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
