/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:19:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/17 16:20:36 by  qcoudeyr        ###   ########.fr       */
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
			return (0);
// Need to handle error here ! in case there is a probleme in the map!
		lib->map = create_map_ptn(x, y, v);
		map_addelement(&first, &p_y, &p_e, lib->map);
		x++;
	}
	if (lib->xlen < x)
		lib->xlen = x;
	lib->map = first;
	return (1);
}

int	get_map_info(t_cub *t)
{
	char	*temp;
	char	*buf;
	int		s;

	buf = ft_calloc(100000, sizeof(char));
	s = read(t->fd_map, buf, 100000);
	buf[s] = 0;
	temp = ft_strnstr(buf, "NO ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "NO ", s) == NULL)
		t->lib->no.fname = get_texture_path(temp + 3);
	else
		return (printerrf("Error !\n NO WAll is not set !\n", buf));
	temp = ft_strnstr(buf, "SO ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "SO ", s) == NULL)
		t->lib->so.fname = get_texture_path(temp + 3);
	else
		return (printerrf("Error !\n SO WAll is not set !\n", buf));
	temp = ft_strnstr(buf, "WE ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "WE ", s) == NULL)
		t->lib->we.fname = get_texture_path(temp + 3);
	else
		return (printerrf("Error !\n WE WAll is not set !\n", buf));
	temp = ft_strnstr(buf, "EA ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "EA ", s) == NULL)
		t->lib->ea.fname = get_texture_path(temp + 3);
	else
		return (printerrf("Error !\n EA WAll is not set !\n", buf));
	temp = ft_strnstr(buf, "F ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "F ", s) == NULL)
		get_color(t, temp + 2, 1);
	else
		return (printerrf("Error !\n Floor color not set !\n", buf));
	temp = ft_strnstr(buf, "C ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "C ", s) == NULL)
		get_color(t, temp + 2, -1);
	else
		return (printerrf("Error !\n Celling color not set !\n", buf));
	get_map(t, buf);
	buf = pfree(buf);
	get_ply_pos(t);
	return (1);
}

int	check_color(int color)
{
	if (color < 0 || color > 255)
		return (-1);
	else
		return (0);
}

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
