/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:21:10 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/22 13:07:01 by  qcoudeyr        ###   ########.fr       */
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
	t_coord	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	get_point(t_coord **list, t_data *d, char *str, int *y)
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
				z = 0;
			addPoint(list, x, *y, z);
			x++;
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
		i++;
	}
	if (x > d->x_max)
		d->x_max = x;
}

void	read_map(t_coord **list, t_data *d, char **argv)
{
	int			fd;
	char		*line;
	int			y;

	y = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		get_point(list, d, line, &y);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	if (y > d->y_max)
		d->y_max = y;
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
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
	*x *= 30;
	*y *= 30;
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
		my_mlx_pixel_put(data, point->x + (data->win_w / 3), point->y + (data->win_h / 3), point->color);
		point = point->next;
	}
	point = coord;
	nextp = coord->next;
	while (nextp != NULL)
	{
		if (nextp->y == point->y)
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

	img.x_max = 0;
	img.y_max = 0;
	img.win_w = 1200;
	img.win_h = 900;
	listcoord = NULL;
	if (argc != 2)
		return (0);
	else
		read_map(&listcoord, &img, argv);
	ft_printf("x=%d\n y=%d\n", img.x_max, img.y_max);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1200, 900, "Fdf");
	img.img = mlx_new_image(mlx.ptr, img.win_w, img.win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	put_on_map(&img, listcoord);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, handle_key, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
