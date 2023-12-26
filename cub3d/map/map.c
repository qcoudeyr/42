/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:33:30 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/26 17:47:06 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	if (map->px == NULL)
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

void	map_addelement(t_map **first, t_map **p_x, t_map **p_e, t_mlx *lib)
{
	if (*p_x != NULL)
	{
		(*p_x)->nx = lib->map;
		*p_x = (*p_x)->ny;
	}
	if (*first == NULL)
		*first = lib->map;
	if (*p_e != NULL)
		(*p_e)->ny = lib->map;
	lib->map->py = *p_e;
	lib->map->px = *p_x;
	lib->map->first = *first;
	*p_e = lib->map;
	lib->map = lib->map->ny;
}
