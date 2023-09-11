/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:19:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/10 15:18:04 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*origin_map(t_map *map)
{
	if (map->px == NULL)
		return (map);
	while(map->px != NULL)
		map = map->px;
	return (map);
}

int	arg_checker(int argc, char **argv)
{
	void	*ptr;

	if (argc != 2)
		return (0);
	ptr = ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]));
	if (ptr == argv[1] || ptr == NULL)
		return (0);
	return (1);
}


t_map *create_map_element(int x, int y, int value, t_map *p_y, t_map *p_x)
{
	t_map *new_element = (t_map *)malloc(sizeof(t_map));
	if (new_element != NULL)
	{
		new_element->x = x;
		new_element->y = y;
		new_element->value = value;
		new_element->nx = NULL;
		new_element->ny = NULL;
		new_element->py = p_y;
		new_element->px = p_x;
	}
	if (p_x != NULL)
		p_x->nx = new_element;
	return (new_element);
}

int	parse(char *str, t_mlx *lib, int x, t_map *p_x)
{
	char	**temp;
	t_map	*p_e;
	t_map	*first;
	int y;

	y = 0;
	p_e = NULL;
	first = NULL;
	if (str == NULL)
		return (0);
	temp = (char **)ft_split((char *)str, ' ');
	while (temp[y])
	{
		lib->map = create_map_element(x, y, ft_atoi(temp[y]), p_e, p_x);
		if (first == NULL)
			first = lib->map;
		lib->map->first = first;
		if (p_e != NULL)
			p_e->ny = lib->map;
		if (p_x != NULL)
			p_x = p_x->ny;
		p_e = lib->map;
		lib->map = lib->map->ny;
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
	int	fd;
	int	x;
	t_map	*p_x;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open the file");
		ft_freemap(lib);
		exit (0);
	}
	x = 0;
	p_x = NULL;
	while (parse(get_next_line(fd), lib,x, p_x) != 0)
	{
		p_x = lib->map;
		x++;
	}
	lib->xlen = x;
	lib->map = origin_map(lib->map->first);
	lib->map_origin = origin_map(lib->map->first);
	lib->scalex = (lib->sizey / lib->xlen)/2;
	lib->scaley = (lib->sizex / lib->ylen)/2;
}

