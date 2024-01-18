/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:17:23 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/18 12:08:41 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_map(char *str)
{
	int	i;

	i = 0;
	if (!str && !*str)
		return (0);
	while (str[i])
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

void	cpy_map_to_int(t_cub *t, t_mlx *lib)
{
	while (lib->map->y < lib->ylen)
	{
		while (lib->map->x < lib->xlen)
		{
			t->wmap[lib->map->y][lib->map->x] = lib->map->value;
			if (lib->map->nx == NULL)
				break ;
			lib->map = lib->map->nx;
		}
		if (lib->map->first->ny != NULL)
			lib->map = lib->map->first->ny;
		else
			break ;
	}
}

void	format_map(t_cub *t, t_mlx *lib)
{
	int	y;
	int	x;

	y = 0;
	t->wmap = ft_calloc(lib->ylen + 1, sizeof(int *));
	t->ply->wmap = t->wmap;
	while (y <= lib->ylen)
	{
		t->wmap[y] = ft_calloc((lib->xlen +1), sizeof(int));
		x = 0;
		while (x <= lib->xlen)
			t->wmap[y][x++] = 1;
		y++;
	}
	if (!lib->map)
		return ;
	cpy_map_to_int(t, lib);
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
	while (is_map(tmp[i++]) == 0)
	{
	}
	if (tmp[i] != NULL)
		grep_map(t->lib, tmp + (i - 1));
	format_map(t, t->lib);
	tmp = tabfree((void **) tmp);
}
