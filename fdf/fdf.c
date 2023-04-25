/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:21:10 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/04/18 22:06:19 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

void	close_window(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	exit(0);
}

int	handle_key(int keycode, void *mlx)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Fdf");

	mlx_hook(mlx_win, 17, 1L << 17, close_window, mlx);
	mlx_hook(mlx_win, 2, 1L << 0, handle_key, mlx);
	mlx_loop(mlx);

	return (0);
}
