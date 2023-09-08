/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:19:14 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/08 13:55:43 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	random_color(int value)
{
	int	red = 255 - value;
	int	green = 255 - value;
	int	blue = 255 - value;

	int color = (red << 16) | (green << 8) | blue;

	return color;
}


int	tcolor(int red, int green, int blue)
{
	if (red > 0)
		red = 255;
	return ((red << 16) | (green << 8) | blue);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_dot(t_data *data, int x, int y, int color)
{
	my_mlx_pixel_put(data, x, y, color);
	my_mlx_pixel_put(data, x+1, y, color);
	my_mlx_pixel_put(data, x+2, y, color);
	my_mlx_pixel_put(data, x, y+1, color);
	my_mlx_pixel_put(data, x+1, y+1, color);
	my_mlx_pixel_put(data, x+2, y+1, color);
	my_mlx_pixel_put(data, x, y+2, color);
	my_mlx_pixel_put(data, x+1, y+2, color);
	my_mlx_pixel_put(data, x+2, y+2, color);
}

void	line_put(t_data *data, t_map *first, t_map *second)
{
	put_dot(data, first->x, y, color);

}

int	background(t_mlx *lib, t_data *data)
{
	for(int x = 0;x < 1280;x++)
	{
		for(int y = 0; y < 800; y++)
			my_mlx_pixel_put(data, x, y, random_color(0));
	}
	mlx_put_image_to_window(lib->mlx, lib->current_win, data->img, 0, 0);
}

void	addmap(t_mlx *lib, t_data *data)
{
	t_map	*line;
	int color = (255 << 16);
	int	scalex;
	int	scaley;

	scalex = (lib->sizey / lib->xlen);
	ft_printf("sizey=%i | ylen=%i | scalex%i\n", lib->sizey ,lib->xlen, scalex);
	scaley = (lib->sizex / lib->ylen);
	ft_printf("sizex=%i | xlen=%i | scaley=%i\n", lib->sizex ,lib->ylen, scaley);
	line = lib->map->first;
	while (lib->map != NULL)
	{
		while(lib->map != NULL)
		{
			line_put(data, (lib->map->y * scaley),  (lib->map->x * scalex),tcolor((lib->map->value),0,0));
			lib->map = lib->map->nx;
		}
		lib->map = line->ny;
		line = line->ny;
	}
	mlx_put_image_to_window(lib->mlx, lib->current_win, data->img, 0, 0);
}
