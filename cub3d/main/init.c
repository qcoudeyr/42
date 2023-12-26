/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:53:29 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/26 09:06:32 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
