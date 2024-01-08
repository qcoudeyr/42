/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:53:29 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/08 13:47:04 by  qcoudeyr        ###   ########.fr       */
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
	lib->c_win = mlx_new_window(lib->mlx, lib->sizex, \
lib->sizey, "Qcoudeyr - QuanranteDoom3D - Menu");
}

void	lib_init(t_mlx *lib)
{
	lib->data = ft_calloc(1, sizeof(t_data));
	lib->tampon = ft_calloc(1, sizeof(t_data));
	lib->sizex = 960;
	lib->sizey = 540;
	lib->xlen = 0;
	lib->ylen = 0;
	lib->scale[0] = 0;
	lib->scale[1] = 0;
	lib->offset[0] = 150;
	lib->offset[1] = 150;
	lib->vsin = 0.523599;
	lib->vcos = 0.523599;
	lib->multheight = 1;
	lib->x_angle = 0;
	lib->y_angle = 0;
	lib->z_angle = 0;
	lib->tx_no = NULL;
	lib->tx_so = NULL;
	lib->tx_we = NULL;
	lib->tx_ea = NULL;
	lib->map_origin = NULL;
	lib->map = NULL;
	lib->mlx = NULL;
	lib->c_win = NULL;
}

void	init_player(t_ply *p)
{
	//x and y start position
	p->posX = 22.0;
	p->posY = 11.5;
	//initial direction vector
	p->dirX = -1.0;
	p->dirY = 0.0;
	//the 2d raycaster version of camera plane
	p->planeX = 0.0;
	p->planeY = 0.66;
	//time of current frame
	p->time = 0;
	//time of previous frame
	p->oldTime = 0;
}

void	init_struct(t_cub *t)
{
	t->fd_map = 0;
	t->ply = ft_calloc(1, sizeof(t_ply));
	init_player(t->ply);
	t->lib = ft_calloc(1, sizeof(t_mlx));
	lib_init(t->lib);
}

