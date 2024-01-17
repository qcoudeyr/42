/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:34:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/17 16:10:04 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_render(t_cub *t)
{
	t->rdr->camerax = 2 * t->rdr->x / (double)t->lib->sizex - 1;
	t->rdr->raydirx = t->ply->dirx + t->ply->planex * t->rdr->camerax;
	t->rdr->raydiry = t->ply->diry + t->ply->planey * t->rdr->camerax;
	t->rdr->mapx = (int)t->ply->posx;
	t->rdr->mapy = (int)t->ply->posy;
	if (t->rdr->raydirx == 0)
		t->rdr->deltadistx = 1e30;
	else
		t->rdr->deltadistx = ft_abs(1 / t->rdr->raydirx);
	if (t->rdr->raydiry == 0)
		t->rdr->deltadisty = 1e30;
	else
		t->rdr->deltadisty = ft_abs(1 / t->rdr->raydiry);
	t->rdr->hit = 0;
}

void	texture_put(t_cub *t, int x, int y, unsigned int color)
{
	char	*dst;
	t_data	*data;

	data = t->lib->data;
	if (x >= 0 && y >= 0 && x < t->lib->sizex && y < t->lib->sizey)
	{
		dst = data->addr + (y * data->line_length + x * \
	(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_arrow(t_data *data, t_cub *t)
{
	int				x;
	int				y;
	struct s_arrow	arr;

	arr.x = (int)(t->ply->posy + 1) * 10;
	arr.y = (int)(t->ply->posx + 1) * 10;
	arr.size = 10;
	arr.color = trgb(0, 255, 0, 0);
	x = arr.x - arr.size / 2;
	while (x <= arr.x + arr.size / 2)
		pixel_put(data, x++, arr.y, arr.color);
	y = arr.y - arr.size / 2;
	while (y <= arr.y + arr.size / 2)
	{
		x = arr.x - arr.size / 2;
		while (x <= arr.x + arr.size / 2)
		{
			if ((x - arr.x) + (y - arr.y) >= -arr.size / 2 && (x - arr.x) - \
			(y - arr.y) <= arr.size / 2 && (x - arr.x) + (y - arr.y) <= \
			arr.size / 2 && (x - arr.x) - (y - arr.y) >= -arr.size / 2)
				pixel_put(data, x, y, arr.color);
			x++;
		}
		y++;
	}
}

int	render(t_cub *t)
{
	t->rdr->x = 0;
	print_background(t);
	while (t->rdr->x < t->lib->sizex)
	{
		init_render(t);
		raydir_calcul(t);
		check_hit_wall(t);
		texture_calcul(t);
		draw_texture(t);
		t->rdr->x++;
	}
	mlx_clear_window(t->lib->mlx, t->lib->c_win);
	mlx_put_image_to_window(t->lib->mlx, t->lib->c_win, \
		t->lib->data->img, 0, 0);
	dspl_map(t, t->lib);
	return (0);
}
