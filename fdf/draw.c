/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:19:14 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/11 12:57:49 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int *z, t_mlx *lib)
{
	int	previous_x;
	int	previous_y;
	int	previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	*x = (previous_x - previous_y) * cos(lib->vcos);
	*y = -previous_z + (previous_x + previous_y) * sin(lib->vsin);
}

void	put_dot(t_data *data, int x, int y, int color)
{
	my_mlx_pixel_put(data, x, y, color);
	my_mlx_pixel_put(data, x +1, y, color);
	my_mlx_pixel_put(data, x +2, y, color);
	my_mlx_pixel_put(data, x, y +1, color);
	my_mlx_pixel_put(data, x +1, y +1, color);
	my_mlx_pixel_put(data, x +2, y +1, color);
	my_mlx_pixel_put(data, x, y +2, color);
	my_mlx_pixel_put(data, x +1, y +2, color);
	my_mlx_pixel_put(data, x +2, y +2, color);
}

void	line_draw(t_mlx *lib, t_map *second, int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	float	x_increment;
	float	y_increment;
	float	steps;
	float	x;
	float	y;
	int		i;

	i = 0;
	dx = x1 - x0;
	dy = y1 - y0;

	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	x_increment = (float)dx / steps;
	y_increment = (float)dy / steps;
	x = x0;
	y = y0;
	while (i <= steps)
	{
		if (x >= 0 && y >= 0 && x <= lib->sizey && y <= lib->sizex)
		{
			my_mlx_pixel_put(lib->data, (int)y, (int)x, \
			tcolor(second->value * 20, 0, 0));
			my_mlx_pixel_put(lib->data, (int)y, (int)x + 1, \
			tcolor(second->value * 20, 0, 0));
			my_mlx_pixel_put(lib->data, (int)y, (int)x + 2, \
			tcolor(second->value * 20, 0, 0));
		}
		x += x_increment;
		y += y_increment;
		i++;
	}
}

void	line_put(t_mlx *lib, t_map *first, t_map *second, t_data *data)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = (first->x * lib->scalex);
	y0 = (first->y * lib->scaley);
	x1 = (second->x * lib->scalex);
	y1 = (second->y * lib->scaley);
	iso(&y0, &x0, &first->value, lib);
	iso(&y1, &x1, &second->value, lib);
	x0 += lib->offsetx;
	y0 += lib->offsety;
	x1 += lib->offsetx;
	y1 += lib->offsety;
	if (x0 >= 0 && y0 >= 0 && x1 >= 0 && y1 >= 0 && x0 <= lib->sizey \
	&& y0 <= lib->sizex && x1 <= lib->sizey && y1 <= lib->sizex)
	{
		put_dot(data, y0, x0, tcolor(first->value * 20, 0, 0));
		put_dot(data, y1, x1, tcolor(second->value * 20, 0, 0));
	}
	line_draw(lib, second, x0, y0, x1, y1);
}
