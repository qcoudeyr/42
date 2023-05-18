/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:21:10 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/17 10:57:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(t_mlx *s)
{
	mlx_destroy_window(s->ptr, s->win);
	exit(0);
}

int	handle_key(int keycode, t_mlx *s)
{
	if (keycode == 65307)
		close_window(s);
	return (0);
}

void	addPoint(t_coord **list, int x, int y, int z)
{
	t_coord	*newPoint;

	newPoint = (t_coord*) malloc (sizeof(t_coord));
	newPoint->x = x;
	newPoint->y = y;
	newPoint->z = z;
	newPoint->next = NULL;
	if (*list == NULL)
		*list = newPoint;
	else
	{
		t_coord* current = *list;
		while (current->next != NULL)
			current = current->next;
		current->next = newPoint;
	}
}

void	displayPoints(t_coord *list)
{
	t_coord	*current;

	current = list;
	int		y;

	y = 0;
	while (current != NULL)
	{
		ft_printf("%d ", current->z);
		if (current->y > y)
		{
			ft_printf("\n");
			y++;
		}
		current = current->next;
	}
	printf("\n");
}

void	freeMemory(t_coord *list)
{
	t_coord	*current;

	current = list;
	while (current != NULL)
	{
		t_coord* next = current->next;
		free(current);
		current = next;
	}
}

void	get_point(t_coord **list, char *str, int *y)
{
	int	i;
	int	x;
	int	z;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			z = ft_atoi(str + i);
			if (z > 0)
				z = 1;
			addPoint(list, x, *y, z);
			x++;
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
		i++;
	}
}

void	read_map(t_coord **list, char **argv)
{
	int			fd;
	char		*line;
	int			y;

	y = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		get_point(list, line, &y);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	if (line)
		free(line);
	close(fd);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	calcul_iso(int *x, int *y, int z)
{
	/* int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599); */
	*x *= 10;
	*y *= 10;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_on_map(t_data *data, t_coord *coord)
{
	t_coord	*point;
	t_coord	*nextp;
	int		min_x;
	int		min_y;

	point = coord;
	min_x = point->x;
	min_y = point->y;
	while (point != NULL)
	{
		calcul_iso(&point->x, &point->y, point->z);
		if (min_x > point->x)
			min_x = point->x;
		if (min_y > point->y)
			min_y = point->y;
		if (point->z > 0)
			point->color = create_trgb(0, 255, 0, 0);
		else
			point->color = create_trgb(0, 0, 0, 255);
		point = point->next;
	}
	point = coord;
	if (min_x < 0)
		min_x = -min_x;
	if (min_y < 0)
		min_y = -min_y;
	while (point != NULL)
	{
		my_mlx_pixel_put(data, point->x + (data->win_w / 2), point->y + (data->win_h / 2), point->color);
		point = point->next;
	}
	point = coord;
	nextp = coord->next;
	while (nextp != NULL)
	{
		drawLine(data, point->x, point->y, nextp->x, nextp->y);
		point = point->next;
		nextp = nextp->next;
	}

}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_data	img;
	t_coord	*listcoord;

	img.win_w = 1200;
	img.win_h = 900;
	listcoord = NULL;
	if (argc != 2)
		return (0);
	else
		read_map(&listcoord, argv);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1200, 900, "Fdf");
	img.img = mlx_new_image(mlx.ptr, img.win_w, img.win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
/*
	Mettre ici les fonctions qui calculs la position des points et l'envoi
	dans img.img
 */
	put_on_map(&img, listcoord);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, handle_key, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
