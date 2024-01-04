/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:19:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/04 11:50:32 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
Pour la gestion du parsing:
Les espace sont sont a gerer comme des -1 soit non existant pour que la
map reste coherente;

adapter le parsing fdf pour la map en 0 et en 1 et supprimer les variables
multiplicatrices;

chercher sur la map le point n-1 ou n+1 si il existe, et si non,
verifier que n soit un 1 sinon erreur !
 */

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
		map_addelement(&first, &p_y, &p_e, lib);
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
	while(str[i])
	{
		if (ft_strchr("01 NSEW", str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	format_map(t_mlx *lib)
{
	if (!lib->map)
		return ;
	while (lib->map->y <= lib->ylen && lib->map->x <= lib->xlen)
	{
		while (lib->map->x < lib->xlen)
	{
		if (!lib->map->nx)
		{
			lib->map->nx = create_map_ptn(lib->map->x + 1, lib->map->y, -1);
			map_addelement(&lib->map->first, &lib->map->py->nx, &lib->map, lib);
		}
		lib->map = lib->map->nx;
	}
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
	int		i;

	i = 0;
	tmp = ft_split(str, '\n');
	while (is_map(tmp[i++]) == 0);
	if (tmp[i] != NULL)
		grep_map(t->lib, tmp + (i - 1));
	format_map(t->lib->map);
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
		t->lib->tx_no = get_texture_path(temp + 3);
	else
		return (printerrf("Error !\n NO WAll is not set !\n", buf));
	temp = ft_strnstr(buf, "SO ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "SO ", s) == NULL)
		t->lib->tx_so = get_texture_path(temp + 3);
	else
		return (printerrf("Error !\n SO WAll is not set !\n", buf));
	temp = ft_strnstr(buf, "WE ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "WE ", s) == NULL)
		t->lib->tx_we = get_texture_path(temp + 3);
	else
		return (printerrf("Error !\n WE WAll is not set !\n", buf));
	temp = ft_strnstr(buf, "EA ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "EA ", s) == NULL)
		t->lib->tx_ea = get_texture_path(temp + 3);
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

int	read_map(t_cub *t, t_mlx *lib)
{
/*
if (check_map(fd) == -1)
		return (ft_printf("Error !\nMap file have invalid caractere in it!")); */
	if (get_map_info(t) == -1)
		return (-1);
	if (check_error_map(origin_map(lib->map)) != 0)
		return (-1);
	lib->scalex = (lib->sizey / lib->xlen) / 2;
	lib->scaley = (lib->sizex / lib->ylen) / 2;
	return (1);
}
