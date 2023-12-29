/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:19:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/29 15:09:51 by  qcoudeyr        ###   ########.fr       */
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
		t->lib->fd_no = open(get_texture_path(temp + 3), O_RDONLY);
	else
		return (-1);
	temp = ft_strnstr(buf, "SO ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "SO ", s) == NULL)
		t->lib->fd_so = open(get_texture_path(temp + 3), O_RDONLY);
	else
		return (-1);
	temp = ft_strnstr(buf, "WE ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "WE ", s) == NULL)
		t->lib->fd_we = open(get_texture_path(temp + 3), O_RDONLY);
	else
		return (-1);
	temp = ft_strnstr(buf, "EA ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "EA ", s) == NULL)
		t->lib->fd_ea = open(get_texture_path(temp + 3), O_RDONLY);
	else
		return (-1);
	temp = ft_strnstr(buf, "F ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "F ", s) == NULL)
		get_color(t, temp + 2, 1);
	else
		return (-1);
	temp = ft_strnstr(buf, "C ", s);
	if (temp != NULL && *temp != 0 && ft_strnstr(temp + 2, "C ", s) == NULL)
		get_color(t, temp + 2, -1);
	else
		return (-1);
	buf = pfree(buf);
	return (1);
}

int	read_map(t_cub *t, t_mlx *lib)
{
	int		x;
	t_map	*p_x;


/*
if (check_map(fd) == -1)
		return (ft_printf("Error !\nMap file have invalid caractere in it!")); */
	if (get_map_info(t) == -1)
		return (-1);
	x = 0;
	p_x = NULL;
	while (parse(get_next_line(t->fd_map), lib, x, p_x) != 0)
	{
		p_x = lib->map;
		x++;
	}
	lib->xlen = x;
	lib->map = origin_map(lib->map->first);
	lib->map_origin = origin_map(lib->map->first);
	lib->scalex = (lib->sizey / lib->xlen) / 2;
	lib->scaley = (lib->sizex / lib->ylen) / 2;
	return (1);
}
