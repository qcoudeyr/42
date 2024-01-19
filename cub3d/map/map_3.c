/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:05:37 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/19 11:59:35 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_texture(t_mlx *lib)
{
	lib->no.ptr = mlx_xpm_file_to_image(lib->mlx, lib->no.fname, \
	&lib->no.w, &lib->no.h);
	lib->so.ptr = mlx_xpm_file_to_image(lib->mlx, lib->so.fname, \
	&lib->so.w, &lib->so.h);
	lib->ea.ptr = mlx_xpm_file_to_image(lib->mlx, lib->ea.fname, \
	&lib->ea.w, &lib->ea.h);
	lib->we.ptr = mlx_xpm_file_to_image(lib->mlx, lib->we.fname, \
	&lib->we.w, &lib->we.h);
	if (!lib->no.ptr || !lib->so.ptr || !lib->ea.ptr || !lib->we.ptr)
		return (printerr("Error !\nMap textures are not valid !\n"));
	lib->no.ptr->addr = mlx_get_data_addr(&lib->no.ptr->img, \
&lib->no.ptr->bits_per_pixel, &lib->no.ptr->line_length, &lib->no.ptr->endian);
	lib->so.ptr->addr = mlx_get_data_addr(&lib->so.ptr->img, \
&lib->so.ptr->bits_per_pixel, &lib->so.ptr->line_length, &lib->so.ptr->endian);
	lib->ea.ptr->addr = mlx_get_data_addr(&lib->ea.ptr->img, \
&lib->ea.ptr->bits_per_pixel, &lib->ea.ptr->line_length, &lib->ea.ptr->endian);
	lib->we.ptr->addr = mlx_get_data_addr(&lib->we.ptr->img, \
&lib->we.ptr->bits_per_pixel, &lib->we.ptr->line_length, &lib->we.ptr->endian);
	return (0);
}

int	map_value(char c)
{
	int	v;

	if (c == ' ')
		v = -1;
	else if (c == 'N')
		v = 2;
	else if (c == 'S')
		v = 3;
	else if (c == 'E')
		v = 4;
	else if (c == 'W')
		v = 5;
	else if (c == '1')
		v = 1;
	else if (c == '0')
		v = 0;
	else
		v = -9;
	return (v);
}

void	map_addelement(t_map **first, t_map **p_y, t_map **p_e, t_map *map)
{
	if (p_y && *p_y != NULL)
	{
		(*p_y)->ny = map;
		map->py = *p_y;
		*p_y = (*p_y)->nx;
	}
	if (first && *first == NULL)
		*first = map;
	if (p_e && *p_e != NULL)
		(*p_e)->nx = map;
	map->px = *p_e;
	map->first = *first;
	*p_e = map;
	map = map->nx;
}
