/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:34:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/17 14:13:17 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	tcolor(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	texture_put(t_cub *t, int x, int y, unsigned int color)
{
	char	*dst;
	t_data	*data;

	data = t->lib->data;
	if (x >= 0 && y >= 0 && x < t->lib->sizex && y < t->lib->sizey)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_pixel(t_data *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + \
	(y * data->line_length + x * (data->bits_per_pixel / 8))));
}

void	draw_arrow(t_data *data, t_arrow *arrow)
{
	int x, y;

	// Draw arrow body
	for (x = arrow->x - arrow->size / 2; x <= arrow->x + arrow->size / 2; x++)
		pixel_put(data, x, arrow->y, arrow->color);

	// Draw arrowhead
	for (y = arrow->y - arrow->size / 2; y <= arrow->y + arrow->size / 2; y++) {
		for (x = arrow->x - arrow->size / 2; x <= arrow->x + arrow->size / 2; x++) {
			if ((x - arrow->x) + (y - arrow->y) >= -arrow->size / 2
				&& (x - arrow->x) - (y - arrow->y) <= arrow->size / 2
				&& (x - arrow->x) + (y - arrow->y) <= arrow->size / 2
				&& (x - arrow->x) - (y - arrow->y) >= -arrow->size / 2)
				pixel_put(data, x, y, arrow->color);
		}
	}
}

void	sqr_print(t_data *data, int	len[2], int offset[2], int color)
{
	t_utils *u;

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
	int	v[2];
	int	color;
	int	offset[2];
	int	x;
	int	y;
	struct s_arrow arr;

	y = 0;
	color = tcolor(30, 30, 30);
	v[0] = 10;
	v[1] = 10;
	while (y < lib->ylen)
	{
		offset[1] = (y + 1) * 10;
		x = 0;
		while (x < lib->xlen)
		{
			offset[0] = (x + 1) * 10;
			if (t->wmap[y][x] == 0)
				color = trgb(0, 255,255,(255 - y));
			else if (t->wmap[y][x] == 1)
				color = trgb(0,153, 73, 0);
			sqr_print(lib->data, v, offset, color);
			x++;
		}
		y++;
	}
	arr.x = (int)(t->ply->posy + 1) *10;
	arr.y = (int)(t->ply->posx + 1) *10;
	arr.size = 10;
	arr.color = trgb(0, 255,0,0);
	draw_arrow(lib->data, &arr);
/* 	offset[1] = (int)(t->ply->posx + 1) *10;
	offset[0] = (int)(t->ply->posy + 1) *10;
	color = trgb(0, 255,0,0);
	sqr_print(lib->data, v, offset, color); */
	mlx_put_image_to_window(lib->mlx, lib->c_win, lib->data->img, 0, 0);
}

double	ft_abs(double i)
{
	if (i < 0)
		return (double)(i * (double)-1);
	else
		return (i);
}

unsigned long getticks(t_cub *t)
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL) != 0)
	{
		perror("gettimeofday failed");
		exit(EXIT_FAILURE);
	}
	if (t->init_t == 0)
	{
		t->init_t = ((tv.tv_sec * 1000UL) + tv.tv_usec / 1000UL);
		gettimeofday(&tv, NULL);
	}
	return (((tv.tv_sec * 1000UL) + (tv.tv_usec / 1000UL)) - t->init_t);
}
void	print_background(t_cub *t)
{
	int y;
	int x;

	y = 0;
	while (y < t->lib->sizey)
	{
		x = 0;
		while (x < t->lib->sizex)
		{
			if (y < (t->lib->sizey / 2))
				pixel_put(t->lib->data, x, y, trgb(80, t->lib->ceiling[0], t->lib->ceiling[1], t->lib->ceiling[2]));
			else
				pixel_put(t->lib->data, x, y, trgb(80, t->lib->floor[0], t->lib->floor[1], t->lib->floor[2]));
			x++;
		}
		y++;
	}
}

void	draw_texture(t_cub *t)
{
	t->rdr->y = t->rdr->drawstart;
	while (t->rdr->y < t->rdr->drawend)
	{
		t->rdr->texy = (int)t->rdr->texpos & (t->texh - 1);
		t->rdr->texpos += t->rdr->step;
		if (t->rdr->side == 1)
		{
			if (t->rdr->raydiry < 0)
				t->rdr->color = get_pixel(t->lib->we.ptr, t->rdr->texx - t->test, t->rdr->texy);
			else
				t->rdr->color = get_pixel(t->lib->ea.ptr, t->rdr->texx,t->rdr->texy);
		}
		else if (t->rdr->side == 0)
		{
			if (t->rdr->raydirx > 0)
				t->rdr->color = get_pixel(t->lib->so.ptr, t->rdr->texx,t->rdr->texy);
			else
				t->rdr->color = get_pixel(t->lib->no.ptr, t->rdr->texx,t->rdr->texy);
		}
		if(t->rdr->side == 1)
			t->rdr->color = (t->rdr->color >> 1) & 8355711;
		texture_put(t, t->rdr->x, t->rdr->y++, t->rdr->color);
	}
}

int	render(t_cub *t)
{
	t->rdr->x = 0;
	print_background(t);
	while (t->rdr->x < t->lib->sizex)
	{
		t->rdr->camerax = 2 * t->rdr->x / (double)t->lib->sizex - 1; //t->rdr->x-coordinate in camera space
		t->rdr->raydirx = t->ply->dirx + t->ply->planex * t->rdr->camerax;
		t->rdr->raydiry = t->ply->diry + t->ply->planey * t->rdr->camerax;
		t->rdr->mapx = (int)t->ply->posx;
		t->rdr->mapy = (int)t->ply->posy;
		t->rdr->deltadistx = (t->rdr->raydirx == 0) ? 1e30 : ft_abs(1 / t->rdr->raydirx);
		t->rdr->deltadisty = (t->rdr->raydiry == 0) ? 1e30 : ft_abs(1 / t->rdr->raydiry);
		t->rdr->hit = 0;
		if(t->rdr->raydirx < 0)
		{
			t->rdr->stepx = -1;
			t->rdr->sidedistx = (t->ply->posx - t->rdr->mapx) * t->rdr->deltadistx;
		}
		else
		{
			t->rdr->stepx = 1;
			t->rdr->sidedistx = (t->rdr->mapx + 1.0 - t->ply->posx) * t->rdr->deltadistx;
		}
		if(t->rdr->raydiry < 0)
		{
			t->rdr->stepy = -1;
			t->rdr->sidedisty = (t->ply->posy - t->rdr->mapy) * t->rdr->deltadisty;
		}
		else
		{
			t->rdr->stepy = 1;
			t->rdr->sidedisty = (t->rdr->mapy + 1.0 - t->ply->posy) * t->rdr->deltadisty;
		}
		while(t->rdr->hit == 0)
		{
			if(t->rdr->sidedistx < t->rdr->sidedisty)
			{
				t->rdr->sidedistx += t->rdr->deltadistx;
				t->rdr->mapx += t->rdr->stepx;
				t->rdr->side = 0;
			}
			else
			{
				t->rdr->sidedisty += t->rdr->deltadisty;
				t->rdr->mapy += t->rdr->stepy;
				t->rdr->side = 1;
			}
			if(t->wmap[t->rdr->mapx][t->rdr->mapy] > 0)
				t->rdr->hit = 1;
		}
		if(t->rdr->side == 0)
			t->rdr->perpwalldist = (t->rdr->sidedistx - t->rdr->deltadistx);
		else
			t->rdr->perpwalldist = (t->rdr->sidedisty - t->rdr->deltadisty);
		t->rdr->lineheight = (int)(t->lib->sizey / t->rdr->perpwalldist);
		t->rdr->drawstart = -t->rdr->lineheight / 2 + t->lib->sizey / 2;
		if(t->rdr->drawstart < 0) t->rdr->drawstart = 0;
		t->rdr->drawend = t->rdr->lineheight / 2 + t->lib->sizey / 2;
		if(t->rdr->drawend >= t->lib->sizey) t->rdr->drawend = t->lib->sizey - 1;
		if (t->rdr->side == 0)
			t->rdr->wallx = t->ply->posy + t->rdr->perpwalldist * t->rdr->raydiry;
		else
			t->rdr->wallx = t->ply->posx + t->rdr->perpwalldist * t->rdr->raydirx;
		t->rdr->wallx -= floor((t->rdr->wallx));
		t->rdr->texx = (int)(t->rdr->wallx * (double)(t->lib->no.w));
		if(t->rdr->side == 0 && t->rdr->raydirx > 0)
			t->rdr->texx = t->lib->no.w - t->rdr->texx - 1;
		if(t->rdr->side == 1 && t->rdr->raydiry < 0)
			t->rdr->texx = t->lib->no.w - t->rdr->texx - 1;
		t->rdr->step = 1.0 * t->lib->no.h / t->rdr->lineheight;
		t->rdr->texpos = (t->rdr->drawstart - t->lib->sizey / 2 + t->rdr->lineheight / 2) * t->rdr->step;
		draw_texture(t);
		t->rdr->x++;
	}
	mlx_clear_window(t->lib->mlx, t->lib->c_win);
	mlx_put_image_to_window(t->lib->mlx, t->lib->c_win, t->lib->data->img, 0 , 0);
	dspl_map(t, t->lib);
	return (0);
}
