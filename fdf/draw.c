/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:19:14 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/12 09:44:02 by  qcoudeyr        ###   ########.fr       */
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

void	line_draw(t_mlx *lib, t_map *second, t_line *p)
{
	float	x;
	float	y;
	int		i;

	i = 0;
	x = p->x0;
	y = p->y0;
	while (i <= p->steps)
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
		x += p->x_increment;
		y += p->y_increment;
		i++;
	}
}

t_line	*line_math(t_line *p)
{
	p->dx = p->x1 - p->x0;
	p->dy = p->y1 - p->y0;
	if (abs(p->dx) > abs(p->dy))
		p->steps = abs(p->dx);
	else
		p->steps = abs(p->dy);
	p->x_increment = (float)p->dx / p->steps;
	p->y_increment = (float)p->dy / p->steps;
	return (p);
}

void	line_put(t_mlx *lib, t_map *first, t_map *second, t_data *data)
{
	t_line	*p;

	p = malloc(sizeof(t_line));
	p->x0 = (first->x * lib->scalex);
	p->y0 = (first->y * lib->scaley);
	p->x1 = (second->x * lib->scalex);
	p->y1 = (second->y * lib->scaley);
	iso(&p->y0, &p->x0, &first->value, lib);
	iso(&p->y1, &p->x1, &second->value, lib);
	p->x0 += lib->offsetx;
	p->y0 += lib->offsety;
	p->x1 += lib->offsetx;
	p->y1 += lib->offsety;
	if (p->x0 >= 0 && p->y0 >= 0 \
	&& p->x1 >= 0 && p->y1 >= 0 && p->x0 <= lib->sizey \
	&& p->y0 <= lib->sizex && p->x1 <= lib->sizey && p->y1 <= lib->sizex)
	{
		put_dot(data, p->y0, p->x0, tcolor(first->value * 20, 0, 0));
		put_dot(data, p->y1, p->x1, tcolor(second->value * 20, 0, 0));
	}
	line_draw(lib, second, line_math(p));
	free(p);
}
