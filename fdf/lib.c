/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:25:08 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/11 12:40:52 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closewin(t_mlx *lib)
{
	mlx_clear_window(lib->mlx, lib->current_win);
	mlx_destroy_window(lib->mlx, lib->current_win);
	mlx_destroy_image(lib->mlx, lib->data->img);
	mlx_destroy_image(lib->mlx, lib->tampon->img);
	mlx_loop_end(lib->mlx);
	return (0);
}

void	reload_map(t_mlx *lib, t_data *data)
{
	mlx_clear_window(lib->mlx, lib->current_win);
	mlx_put_image_to_window(lib->mlx, lib->current_win, lib->tampon->img, 0, 0);
	mlx_destroy_image(lib->mlx, lib->data->img);
	lib->data->img = mlx_new_image(lib->mlx, lib->sizex, lib->sizey);
	lib->data->addr = mlx_get_data_addr(lib->data->img, \
	&lib->data->bits_per_pixel, &lib->data->line_length, &lib->data->endian);
	background(lib, lib->data);
	addmap(lib, data);
}

int	keyhandle(int keycode, t_mlx *lib)
{
	if (keycode == 65307)
		return (closewin(lib));
	else
	{
		if (keycode == 65364)
			lib->offsetx += 10;
		if (keycode == 65362)
			lib->offsetx -= 10;
		if (keycode == 65363)
			lib->offsety += 10;
		if (keycode == 65361)
			lib->offsety -= 10;
		reload_map(lib, lib->data);
	}
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_mlx *lib)
{
	if (button == 4)
	{
		if (lib->scalex > 2 && lib->scaley > 2)
		{
			lib->scalex = 0.90 * (double)lib->scalex;
			lib->scaley = 0.90 * (double)lib->scaley;
		}
		reload_map(lib, lib->data);
	}
	else if (button == 5)
	{
		if (lib->scalex < 10 && lib->scaley < 10)
		{
			lib->scalex += 1;
			lib->scaley += 1;
		}
		else
		{
			lib->scalex = 1.2 * (double)lib->scalex;
			lib->scaley = 1.2 * (double)lib->scaley;
		}
		reload_map(lib, lib->data);
	}
	return (0);
}

void	ft_freemap(t_mlx *lib)
{
	t_map	*current;
	t_map	*next_x;
	t_map	*next_y;
	t_map	*temp;

	current = lib->map_origin;
	while (current != NULL)
	{
		next_x = current->nx;
		next_y = current->ny;
		free(current);
		current = next_x;
		while (next_y != NULL)
		{
			temp = next_y;
			next_y = next_y->ny;
			free(temp);
		}
	}
	lib->map == NULL;
}
