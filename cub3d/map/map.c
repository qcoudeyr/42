/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:33:30 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/04 10:00:13 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_error_map(t_map *map)
{
	if (map == NULL)
		return (-1);
	while (map->nx && map->ny)
	{
		if ((!map->px || !map->py || !map->nx || !map->ny) && (map->value != 1 && map->value != -1))
			return (-1);
		else if (((map->px && map->px->value == -1) || (map->py && map->py->value == -1) \
		|| (map->ny && map->ny->value == -1) || (map->nx && map->nx->value == -1)) && \
		(map->value != 1 || map->value != -1))
			return (-1);
		if (!map->nx)
			map = map->first->ny;
		map = map->nx;
	}
	return (0);
}

void	addmap(t_mlx *lib, t_data *data)
{
	t_map	*line;

	line = lib->map->first;
	while (lib->map != NULL)
	{
		while (lib->map != NULL)
		{}
		lib->map = line->ny;
		line = line->ny;
	}
	mlx_put_image_to_window(lib->mlx, lib->current_win, data->img, 0, 0);
	lib->map = lib->map_origin;
}

t_map	*origin_map(t_map *map)
{
	if (map->px == NULL && map->py == NULL)
		return (map);
	while (map->px != NULL)
		map = map->px;
	if (map->py == NULL)
		return (map);
	while (map->py != NULL)
		map = map->py;
	return (map);
}

t_map	*create_map_ptn(int x, int y, int value)
{
	t_map	*new_element;

	new_element = (t_map *)malloc(sizeof(t_map));
	if (new_element != NULL)
	{
		new_element->x = x;
		new_element->y = y;
		new_element->value = value;
		new_element->nx = NULL;
		new_element->ny = NULL;
		new_element->py = NULL;
		new_element->px = NULL;
	}
	return (new_element);
}

void	map_addelement(t_map **first, t_map **p_y, t_map **p_e, t_mlx *lib)
{
	if (*p_y != NULL)
	{
		(*p_y)->ny = lib->map;
		lib->map->py = *p_y;
		*p_y = (*p_y)->nx;
	}
	if (*first == NULL)
		*first = lib->map;
	if (*p_e != NULL)
		(*p_e)->nx = lib->map;
	lib->map->px = *p_e;
	lib->map->first = *first;
	*p_e = lib->map;
	lib->map = lib->map->nx;
}
