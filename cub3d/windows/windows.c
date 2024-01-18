/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:30:16 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/18 17:00:04 by  qcoudeyr        ###   ########.fr       */
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

void	print_background(t_cub *t)
{
	int	y;
	int	x;

	y = 0;
	while (y < t->lib->sizey)
	{
		x = 0;
		while (x < t->lib->sizex)
		{
			if (y < (t->lib->sizey / 2))
				pixel_put(t->lib->data, x, y, trgb(80, t->lib->ceiling[0], \
	t->lib->ceiling[1], t->lib->ceiling[2]));
			else
				pixel_put(t->lib->data, x, y, trgb(80, t->lib->floor[0], \
	t->lib->floor[1], t->lib->floor[2]));
			x++;
		}
		y++;
	}
}

void	sqr_print(t_data *data, int len[2], int offset[2], int color)
{
	t_utils	*u;

	u = ft_calloc(1, sizeof(t_utils));
	utils_init(u);
	while (u->y <= len[1])
	{
		u->x = 0;
		while (u->x <= len[0])
		{
			pixel_put(data, (offset[0] + u->x), (offset[1] + u->y), color);
			u->x++;
		}
		u->y++;
	}
	u = pfree(u);
}

void	dspl_map(t_cub *t, t_mlx *lib)
{
	t_utils	*u;

	u = ft_calloc(1, sizeof(t_utils));
	utils_init(u);
	u->y = 0;
	while (u->y < lib->ylen)
	{
		u->offset[1] = (u->y + 1) * 10;
		u->x = 0;
		while (u->x < lib->xlen)
		{
			u->offset[0] = (u->x + 1) * 10;
			if (t->wmap[u->y][u->x] == 0)
				u->color = trgb(0, 255, 255, (255 - u->y));
			else if (t->wmap[u->y][u->x] == 1)
				u->color = trgb(0, 153, 73, 0);
			sqr_print(lib->data, u->v, u->offset, u->color);
			u->x++;
		}
		u->y++;
	}
	utils_free(u);
	draw_arrow(lib->data, t);
	mlx_put_image_to_window(lib->mlx, lib->c_win, lib->data->img, 0, 0);
}
