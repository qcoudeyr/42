/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:19:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/15 12:46:31 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_value(char c)
{
	int	v;

	if (c == ' ')
		v = 1;
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
			return (0);// Need to handle error here ! in case there is a probleme in the map!
		lib->map = create_map_ptn(x, y, v);
		map_addelement(&first, &p_y, &p_e, lib->map);
		x++;
	}
	if (lib->xlen < x)
		lib->xlen = x;
	lib->map = first;
	return (1);
}

char	*get_texture_path(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_calloc(1000, sizeof(char));
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

void	get_color(t_cub *t, char *str, int s)
{
	char **temp;
	char *value;
	int	i;

	value = get_texture_path(str);
	temp = ft_split(value, ',');
	value = pfree(value);
	i = -1;
	if (s == 1)
	{
		while (i++ < 2)
			t->lib->floor[i] = ft_atoi(temp[i]);
	}
	else
	{
		while (i++ < 2)
			t->lib->ceiling[i] = ft_atoi(temp[i]);
	}
	temp = tabfree((void **)temp);
}

int	is_map(char *str)
{
	int	i;

	i = 0;
	if (!str && !*str)
		return (0);
	while(str[i])
	{
		if (ft_strchr("012 NSEW", str[i]) == 0)
		{
			if (ft_strchr("\n", str[i]) == 0)
				return (0);
			else if (ft_strchr("\n", str[i + 1]) != 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void	format_map(t_cub *t, t_mlx *lib)
{
	int	y;
	int	x;

	y = 0;
	t->wmap = ft_calloc((lib->ylen), sizeof(int *));
	while(y < lib->ylen)
	{
		t->wmap[y] = ft_calloc((lib->xlen), sizeof(int));
		x = 0;
		while (x < lib->xlen)
			t->wmap[y][x++] = 1;
		y++;
	}
	if (!lib->map)
		return ;
	while (lib->map->y < lib->ylen)
	{
		while (lib->map->x < lib->xlen)
		{
			t->wmap[lib->map->y][lib->map->x] = lib->map->value;
			if (lib->map->nx == NULL)
				break;
			lib->map = lib->map->nx;
		}
		if (lib->map->first->ny != NULL)
			lib->map = lib->map->first->ny;
		else
			break;
	}
}

void	grep_map(t_mlx *lib, char **map)
{
	int		y;
	t_map	*p_y;

	y = 0;
	p_y = NULL;
	while (parse(map[y], lib, y, p_y) != 0)
	{
		p_y = lib->map;
		y++;
	}
	lib->ylen = y;
	lib->map = origin_map(lib->map->first);
	lib->map_origin = origin_map(lib->map->first);
}

void	get_map(t_cub *t, char *str)
{
	char	**tmp;
	void	*ptr;
	int		i;

	i = 0;
	ptr = ft_strnstr(str, "\n\n", ft_strlen(str));
	while (ptr != NULL && is_map(ptr) != 1)
	{
		while (*(char *)ptr == '\n' && ptr +1 != NULL)
			ptr++;
		if (ptr != NULL && *(char *)ptr)
			str = ptr;
		ptr = ft_strnstr(ptr, "\n\n", ft_strlen(ptr));
	}
	tmp = ft_split(str, '\n');
	if (is_map(str) != 0)
		ft_printf("here :%s\n", ft_strnstr(str, "\n\n ", ft_strlen(str)));
	else if(is_map(str) != 0)
		ft_printf("here :%s\n", ft_strnstr(str, "\n\n1", ft_strlen(str)));
	while (is_map(tmp[i++]) == 0);
	if (tmp[i] != NULL)
		grep_map(t->lib, tmp + (i - 1));
	format_map(t, t->lib);
	tmp = tabfree((void **) tmp);
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
	return (1);
}

int	check_color(int color)
{
	if (color < 0 || color > 255)
		return (-1);
	else
		return (0);
}

int	read_map(t_cub *t, t_mlx *lib)
{
/*
if (check_map(fd) == -1)
		return (ft_printf("Error !\nMap file have invalid caractere in it!")); */
	if (get_map_info(t) == -1)
		return (-1);
	if (check_error_map(origin_map(lib->map)) != 0)
		return (-1);
	lib->scale[0] = (lib->sizey / lib->xlen) / 2;
	lib->scale[1] = (lib->sizex / lib->ylen) / 2;
	if (check_color(lib->floor[0]) != 0 || check_color(lib->floor[1]) != 0 || check_color(lib->floor[2]) != 0)
		return (printerr("Error !\nColor of the floor is weird !\n"));
	if (check_color(lib->ceiling[0]) != 0 || check_color(lib->ceiling[1]) != 0 || check_color(lib->ceiling[2]) != 0)
		return (printerr("Error !\nColor of the ceiling is weird !\n"));
	return (1);
}

int	get_texture(t_mlx *lib)
{
	lib->no.ptr = mlx_xpm_file_to_image(lib->mlx, lib->no.fname, &lib->no.w, &lib->no.h);
	lib->so.ptr = mlx_xpm_file_to_image(lib->mlx, lib->so.fname, &lib->so.w, &lib->so.h);
	lib->ea.ptr = mlx_xpm_file_to_image(lib->mlx, lib->ea.fname, &lib->ea.w, &lib->ea.h);
	lib->we.ptr = mlx_xpm_file_to_image(lib->mlx, lib->we.fname, &lib->we.w, &lib->we.h);
	if (!lib->no.ptr || !lib->so.ptr || !lib->ea.ptr || !lib->we.ptr)
		return (printerr("Error !\nMap textures are not valid !\n"));
	lib->no.ptr->addr = mlx_get_data_addr(&lib->no.ptr->img, &lib->no.ptr->bits_per_pixel, &lib->no.ptr->line_length, &lib->no.ptr->endian);
	lib->so.ptr->addr = mlx_get_data_addr(&lib->so.ptr->img, &lib->so.ptr->bits_per_pixel, &lib->so.ptr->line_length, &lib->so.ptr->endian);
	lib->ea.ptr->addr = mlx_get_data_addr(&lib->ea.ptr->img, &lib->ea.ptr->bits_per_pixel, &lib->ea.ptr->line_length, &lib->ea.ptr->endian);
	lib->we.ptr->addr = mlx_get_data_addr(&lib->we.ptr->img, &lib->we.ptr->bits_per_pixel, &lib->we.ptr->line_length, &lib->we.ptr->endian);
	return (0);
}
