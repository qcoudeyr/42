/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:21:10 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/07 15:08:07 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


void	closewin(t_mlx *lib)
{
	mlx_destroy_image(lib->mlx, lib->data.img);
	mlx_destroy_image(lib->mlx, lib->menu.img);
	mlx_clear_window(lib->mlx, lib->current_win);
	mlx_destroy_window(lib->mlx, lib->current_win);
	mlx_loop_end(&lib);
	exit(1);
}


/* void	read_map(int fd)
{
	char	*map;
	char	*temp;

	map = ft_calloc(1, sizeof(char));
	while ( )
} */

void	transition(t_mlx *lib, t_data *data)
{
	mlx_clear_window(lib->mlx, lib->current_win);
	mlx_put_image_to_window(lib->mlx,lib->current_win, data->img, 0, 0);
}


int	keyhandle(int keycode, t_mlx *lib)
{
	ft_printf("%i\n", keycode);
	if (keycode == 65307)
		closewin(lib);
	if (keycode == 100)
		transition(lib, &lib->data);
	if (keycode == 115)
		transition(lib, &lib->menu);
 	if (keycode == 99)
	{
		addmap(lib, &lib->data);
		mlx_string_put(lib->mlx, lib->current_win, 500, 500, trgb(0,255,0,0), "Ceci est un test /");
	}


	return 0;
}

void ft_freemap(t_mlx *lib)
{
	t_map *current = lib->map;

	while (current != NULL)
	{
		t_map *next_x = current->nx;
		t_map *next_y = current->ny;
		free(current);
		current = next_x;
		while (next_y != NULL)
		{
			t_map *temp = next_y;
			next_y = next_y->ny;
			free(temp);
		}
	}

	lib->map = NULL; // Set lib->map to NULL to indicate that the map is now empty
}

int	main(int argc, char **argv)
{
	//variable declaration
	t_mlx	*lib;

	lib = malloc(sizeof(t_mlx));
	if (arg_checker(argc, argv) == 0)
		return (ft_printf("Error, Usage : './fdf <filename>.fdf'\n"));
	read_map(argv[1], lib);
	lib->sizex = 1280;
	lib->sizey = 800;
	lib->ylen == 0;
	lib->mlx = mlx_init();
	lib->key.count_1 = 0;
	lib->current_win = mlx_new_window(lib->mlx, lib->sizex, lib->sizey, "Qcoudeyr - FDF - Menu");
	lib->menu.img = mlx_new_image(lib->mlx, lib->sizex, lib->sizey);
	lib->menu.addr = mlx_get_data_addr(lib->menu.img, &lib->menu.bits_per_pixel, &lib->menu.line_length, &lib->menu.endian);
 	lib->data.img = mlx_new_image(lib->mlx, lib->sizex, lib->sizey);
	lib->data.addr = mlx_get_data_addr(lib->data.img, &lib->data.bits_per_pixel, &lib->data.line_length, &lib->data.endian);
	background(lib, &lib->data);
	background(lib, &lib->menu);
	mlx_hook(lib->current_win, 2, 1L<<0, keyhandle, lib);
	mlx_loop(lib->mlx);
	ft_freemap(lib);
	free(lib);
	return (0);
}

/* 	mlx_get_screen_size(lib->mlx, &lib->sizex, &lib->sizey);
	ft_printf("x = %i | y = %i\n", lib->sizex, lib->sizey); */
