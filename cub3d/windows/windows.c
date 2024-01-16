/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:30:16 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/15 17:33:56 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	closewin(t_mlx *lib)
{
	mlx_clear_window(lib->mlx, lib->c_win);
	mlx_destroy_image(lib->mlx, lib->data->img);
	mlx_destroy_image(lib->mlx, lib->tampon->img);
	mlx_loop_end(lib->mlx);
	return (0);
}
