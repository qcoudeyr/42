/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:53:29 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/26 17:45:39 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_windows(t_mlx *lib)
{
	lib->data->img = mlx_new_image(lib->mlx, lib->sizex, lib->sizey);
	lib->data->addr = mlx_get_data_addr(lib->data->img, \
&lib->data->bits_per_pixel, &lib->data->line_length, &lib->data->endian);
	lib->tampon->img = mlx_new_image(lib->mlx, lib->sizex, lib->sizey);
	lib->tampon->addr = mlx_get_data_addr(lib->tampon->img, \
&lib->tampon->bits_per_pixel, &lib->tampon->line_length, &lib->tampon->endian);
	lib->current_win = mlx_new_window(lib->mlx, lib->sizex, \
lib->sizey, "Qcoudeyr - QuanranteDoom3D - Menu");
}

void	lib_init(t_mlx *lib)
{
	lib->data = ft_calloc(1, sizeof(t_data));
	lib->tampon = ft_calloc(1, sizeof(t_data));
	lib->sizex = 1920;
	lib->sizey = 1080;
	lib->xlen = 0;
	lib->ylen = 0;
	lib->scalex = 0;
	lib->scaley = 0;
	lib->offsetx = 150;
	lib->offsety = 500;
	lib->vsin = 0.523599;
	lib->vcos = 0.523599;
	lib->multheight = 1;
	lib->x_angle = 0;
	lib->y_angle = 0;
	lib->z_angle = 0;
	lib->map_origin = NULL;
	lib->map = NULL;
	lib->mlx = NULL;
	lib->current_win = NULL;
}

void	init_struct(t_cub *t)
{
	t->fd_map = 0;
	t->lib = ft_calloc(1, sizeof(t_mlx));
	lib_init(t->lib);
}
