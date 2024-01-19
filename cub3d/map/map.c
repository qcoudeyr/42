/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:33:30 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/18 17:46:45 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_value(t_cub *t, int **wmap, int y, int x)
{
	if (x == 0 && (wmap[y][x] != 1 && wmap[y][x] != -1))
		return (printerr("Error !\nMap isn't closed !\n"));
	if (x == t->lib->xlen - 1 && (wmap[y][x] != 1 && wmap[y][x] != -1))
		return (printerr("Error !\nMap isn't closed !\n"));
	if (y == 0 && (wmap[y][x] != 1 && wmap[y][x] != -1))
		return (printerr("Error !\nMap isn't closed !\n"));
	if (y == t->lib->ylen - 1 && (wmap[y][x] != 1 && wmap[y][x] != -1))
		return (printerr("Error !\nMap isn't closed !\n"));
	if (wmap[y][x] == -1
		&& ((y > 0 && (wmap[y - 1][x] != 1 && wmap[y - 1][x] != -1))
		|| (x > 0 && (wmap[y][x - 1] != 1 && wmap[y][x - 1] != -1))
		|| (y < t->lib->ylen && (wmap[y + 1][x] != 1 && wmap[y + 1][x] != -1))
		|| (x < t->lib->xlen && (wmap[y][x + 1] != 1 && wmap[y][x + 1] != -1))))
		return (printerr("Error !\nMap isn't closed !\n"));
	return (0);
}

int	check_error_map(t_cub *t)
{
	struct s_utils	*u;

	u = ft_calloc(1, sizeof(t_utils));
	utils_init(u);
	if (t->wmap == NULL)
		return (utils_free(u), printerr("Error !\nMap don't exist !\n"));
	while (u->y < t->lib->ylen)
	{
		u->x = 0;
		while (u->x < t->lib->xlen)
		{
			if (check_value(t, t->wmap, u->y, u->x) == -1)
				return (utils_free(u), -1);
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
