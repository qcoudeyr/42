/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:34:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/04 15:26:23 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	sqr_print(t_data *data, int	len[2], int offset[2], int color)
{
	t_utils *u;

	u = ft_calloc(1, sizeof(t_utils));
	utils_init(u);
	while (u->y <= len[1])
	{
		u->x = 0;
		while (u->x <= len[0])
		{
			pixel_put(data, (offset[0] + u->x), (offset[0] + u->y), color);
			u->x++;
		}
		u->y++;
	}
}

void	dspl_map(t_mlx *lib, t_map *map)
{
	int	v[2];
	int	color;
	int	offset[2];

	v[0] = 5;
	v[1] = 5;
	offset[0] = lib->offset[0] + map->x;
	offset[1] = lib->offset[1] + map->y;
	while (map->ny || map->nx)
	{
		if (map->value == 0)
			color = tcolor(255,255,255);
		else if (map->value == -1)
			color = tcolor(130,130,130);
		else if (map->value == 1)
			color = tcolor(153, 73, 0);
		else
			color = tcolor(0, 255, 0);
		sqr_print(lib->data, v, offset, color);
		if (map->nx)
		{
			map = map->nx;
			offset[0] = lib->offset[0] + (2 * map->x);
		}
		else
		{
			map = map->first->ny;
			offset[0] = lib->offset[0] + (2 * map->x);;
			offset[1] = lib->offset[1] + (2 * map->y);;
		}
	}

}
