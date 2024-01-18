/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:19:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/18 12:03:59 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse(char *str, t_mlx *lib, int y, t_map *p_y)
{
	t_map	*p_e;
	t_map	*first;
	int		x;
	int		v;

	x = 0;
	p_e = NULL;
	first = NULL;
	if (str == NULL || *str == 0)
		return (0);
	while (str[x] != '\0')
	{
		v = map_value(str[x]);
		if (v == -9)
			return (printerr("Error !\nMap have weird value in it !\n"));
		lib->map = create_map_ptn(x, y, v);
		map_addelement(&first, &p_y, &p_e, lib->map);
		x++;
	}
	if (lib->xlen < x)
		lib->xlen = x;
	lib->map = first;
	return (1);
}

int	search_fnc(char **temp, char *buf, int s, t_cub *t)
{
	*temp = ft_strnstr(buf, "F ", s);
	if (*temp != NULL && **temp != 0 && ft_strnstr(*temp + 2, "F ", s) == NULL)
		get_color(t, *temp + 2, 1);
	else
		return (printerrf("Error !\n Floor color not set !\n", buf));
	*temp = ft_strnstr(buf, "C ", s);
	if (temp != NULL && **temp != 0 && ft_strnstr(*temp + 2, "C ", s) == NULL)
		get_color(t, *temp + 2, -1);
	else
		return (printerrf("Error !\n Celling color not set !\n", buf));
	return (0);
}

int	search_texture(char **temp, char *buf, int s, t_cub *t)
{
	*temp = ft_strnstr(buf, "NO ", s);
	if (*temp != NULL && **temp != 0 && ft_strnstr(*temp + 2, "NO ", s) == NULL)
		t->lib->no.fname = get_texture_path(*temp + 3);
	else
		return (printerrf("Error !\n NO WAll is not set !\n", buf));
	*temp = ft_strnstr(buf, "SO ", s);
	if (*temp != NULL && **temp != 0 && ft_strnstr(*temp + 2, "SO ", s) == NULL)
		t->lib->so.fname = get_texture_path(*temp + 3);
	else
		return (printerrf("Error !\n SO WAll is not set !\n", buf));
	*temp = ft_strnstr(buf, "WE ", s);
	if (*temp != NULL && **temp != 0 && ft_strnstr(*temp + 2, "WE ", s) == NULL)
		t->lib->we.fname = get_texture_path(*temp + 3);
	else
		return (printerrf("Error !\n WE WAll is not set !\n", buf));
	*temp = ft_strnstr(buf, "EA ", s);
	if (*temp != NULL && **temp != 0 && ft_strnstr(*temp + 2, "EA ", s) == NULL)
		t->lib->ea.fname = get_texture_path(*temp + 3);
	else
		return (printerrf("Error !\n EA WAll is not set !\n", buf));
	return (0);
}

int	get_map_info(t_cub *t)
{
	char	*temp;
	char	*buf;
	int		s;

	buf = ft_calloc(100000, sizeof(char));
	s = read(t->fd_map, buf, 100000);
	buf[s] = 0;
	search_texture(&temp, buf, s, t);
	search_fnc(&temp, buf, s, t);
	get_map(t, buf);
	buf = pfree(buf);
	get_ply_pos(t);
	return (1);
}

int	read_map(t_cub *t, t_mlx *lib)
{
	if (get_map_info(t) == -1)
		return (-1);
	if (check_error_map(origin_map(lib->map)) != 0)
		return (-1);
	lib->scale[0] = (lib->sizey / lib->xlen) / 2;
	lib->scale[1] = (lib->sizex / lib->ylen) / 2;
	if (check_color(lib->floor[0]) != 0
		|| check_color(lib->floor[1]) != 0
		|| check_color(lib->floor[2]) != 0)
		return (printerr("Error !\nColor of the floor is weird !\n"));
	if (check_color(lib->ceiling[0]) != 0
		|| check_color(lib->ceiling[1]) != 0
		|| check_color(lib->ceiling[2]) != 0)
		return (printerr("Error !\nColor of the ceiling is weird !\n"));
	return (1);
}
