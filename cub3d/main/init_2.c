/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:04:58 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/18 16:59:32 by  qcoudeyr        ###   ########.fr       */
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
lib->sizey, "- Cube3D -");
}

void	utils_init(t_utils *u)
{
	u->i = 0;
	u->x = 0;
	u->y = 0;
	u->z = 0;
	u->c = 0;
	u->v[0] = 10;
	u->v[1] = 10;
	u->color = 0;
	u->offset[0] = 0;
	u->offset[1] = 0;
	u->tmp1 = NULL;
	u->tmp2 = NULL;
	u->str1 = NULL;
	u->str2 = NULL;
	u->lst = NULL;
	u->tab = NULL;
	u->ptr = NULL;
	u->ptr1 = NULL;
	u->ptr2 = NULL;
	u->lstptr = NULL;
}
