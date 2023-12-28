/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:19:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/28 17:50:36 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
Pour la gestion du parsing:
Les espace sont sont a gerer comme des -1 soit non existant pour que la
map reste coherente;

Pour le NO SO WE EA juste a faire un strcmp et prendre la valeur ensuite
en supprimant les espaces.

Gerer les lignes vides par un while (strncmp(temp, "\n", 2) == 0);

Gerer les couleurs par des variables dans la fonction lib lib.f[3] = RGB
et lib.c[3]

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

void	get_map_info(t_cub *t, int fd)
{
	char	*temp;
	char	*buf;
	int		s;

	s = read(fd, buf, 100000);
	buf[s] = 0;
	s = 0;
	if (ft_strnstr(buf, "NO ", 3) != NULL)
	if (ft_strnstr(buf, "SO ", 3) != NULL)
	if (ft_strnstr(buf, "WE ", 3) != NULL)
	if (ft_strnstr(buf, "EA ", 3) != NULL)
}

void	read_map(t_cub *t, char *filename, t_mlx *lib)
{
	int		fd;
	int		x;
	t_map	*p_x;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("open"));
	if (check_map(fd) == -1)
		return (ft_printf("Error !\nMap file have invalid caractere in it!"));
	get_map_info(t, fd);
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
