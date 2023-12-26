/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:21:10 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/26 17:34:20 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	lib_init(t_mlx *lib)
{
	lib->data = malloc(sizeof(t_data));
	lib->tampon = malloc(sizeof(t_data));
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

void	init_windows(t_mlx *lib)
{
	lib->data->img = mlx_new_image(lib->mlx, lib->sizex, lib->sizey);
	lib->data->addr = mlx_get_data_addr(lib->data->img, \
&lib->data->bits_per_pixel, &lib->data->line_length, &lib->data->endian);
	lib->tampon->img = mlx_new_image(lib->mlx, lib->sizex, lib->sizey);
	lib->tampon->addr = mlx_get_data_addr(lib->tampon->img, \
&lib->tampon->bits_per_pixel, &lib->tampon->line_length, &lib->tampon->endian);
	lib->current_win = mlx_new_window(lib->mlx, lib->sizex, \
lib->sizey, "Qcoudeyr - FDF - Menu");
	background(lib, lib->data);
	background(lib, lib->tampon);
}

void	ft_freelib(t_mlx *lib)
{
	ft_freemap(lib);
	free(lib->mlx);
	lib->mlx = NULL;
	free(lib->data);
	lib->data = NULL;
	free(lib->tampon);
	lib->tampon = NULL;
	free(lib);
}

int	main(int argc, char **argv)
{
	t_mlx	*lib;

	if (arg_checker(argc, argv) == 0)
		return (ft_printf("Error, Usage: './fdf <filename>.fdf'\n"));
	lib = malloc(sizeof(t_mlx));
	lib_init(lib);
	read_map(argv[1], lib);
	lib->mlx = mlx_init();
	init_windows(lib);
	addmap(lib, lib->data);
	mlx_mouse_hook(lib->current_win, mouse_scroll, lib);
	mlx_hook(lib->current_win, 2, 1L << 0, keyhandle, lib);
	mlx_hook(lib->current_win, 17, 0, closewin, lib);
	mlx_loop(lib->mlx);
	mlx_destroy_window(lib->mlx, lib->current_win);
	mlx_destroy_display(lib->mlx);
	ft_freelib(lib);
	return (0);
}
