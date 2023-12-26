/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:19:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/26 09:14:50 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	parse(char *str, t_mlx *lib, int x, t_map *p_x)
{
	char	**temp;
	t_map	*p_e;
	t_map	*first;
	int		y;

	y = 0;
	p_e = NULL;
	first = NULL;
	if (str == NULL)
		return (0);
	temp = (char **)ft_split((char *)str, ' ');
	while (temp[y])
	{
		lib->map = create_map_ptn(x, y, ft_atoi(temp[y]));
		map_addelement(&first, &p_x, &p_e, lib);
		free(temp[y]);
		y++;
	}
	if (lib->ylen == 0)
		lib->ylen = y;
	lib->map = first;
	free(temp);
	return (1);
}

void	read_map(char *filename, t_mlx *lib)
{
	int		fd;
	int		x;
	t_map	*p_x;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open the file");
		ft_freemap(lib);
		free_lib(lib);
		exit (0);
	}
	x = 0;
	p_x = NULL;
	while (parse(get_next_line(fd), lib, x, p_x) != 0)
	{
		p_x = lib->map;
		x++;
	}
	lib->xlen = x;
	lib->map = origin_map(lib->map->first);
	lib->map_origin = origin_map(lib->map->first);
	lib->scalex = (lib->sizey / lib->xlen) / 2;
	lib->scaley = (lib->sizex / lib->ylen) / 2;
}
