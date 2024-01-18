/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:33:30 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/18 15:19:16 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_value(int **wmap, int y, int x)
{
	if (x == 0 && wmap[y][x] != )
}

int	check_error_map(t_cub *t)
{
	struct s_utils	*u;

	u = ft_calloc(1, sizeof(t_utils));
	init_struct(u);
	if (t->wmap == NULL)
		return (printerr("Error !\nMap don't exist !\n"));
	while (u->y < t->lib->ylen)
	{
		u->x = 0;
		while (u->x < t->lib->xlen)
		{
			check_value(t->wmap, u->y, u->x);
			u->x++;
		}
		u->y++;
	}
	utils_free(u);
	return (0);
}

void	addmap(t_mlx *lib, t_data *data)
{
	t_map	*line;

	line = lib->map->first;
	while (lib->map != NULL)
	{
		lib->map = line->ny;
		line = line->ny;
	}
	mlx_put_image_to_window(lib->mlx, lib->c_win, data->img, 0, 0);
	lib->map = lib->map_origin;
}

t_map	*origin_map(t_map *map)
{
	if (!map)
		return (map);
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
