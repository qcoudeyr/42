/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:04:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/17 16:15:20 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_side(t_cub *t)
{
	if (t->rdr->side == 1)
	{
		if (t->rdr->raydiry < 0)
			t->rdr->color = get_pixel(t->lib->we.ptr, \
			t->rdr->texx - t->test, t->rdr->texy);
		else
			t->rdr->color = get_pixel(t->lib->ea.ptr, \
			t->rdr->texx, t->rdr->texy);
	}
	else if (t->rdr->side == 0)
	{
		if (t->rdr->raydirx > 0)
			t->rdr->color = get_pixel(t->lib->so.ptr, \
			t->rdr->texx, t->rdr->texy);
		else
			t->rdr->color = get_pixel(t->lib->no.ptr, \
			t->rdr->texx, t->rdr->texy);
	}
	if (t->rdr->side == 1)
		t->rdr->color = (t->rdr->color >> 1) & 8355711;
}

void	draw_texture(t_cub *t)
{
	t->rdr->y = t->rdr->drawstart;
	while (t->rdr->y < t->rdr->drawend)
	{
		t->rdr->texy = (int)t->rdr->texpos & (t->texh - 1);
		t->rdr->texpos += t->rdr->step;
		check_side(t);
		texture_put(t, t->rdr->x, t->rdr->y++, t->rdr->color);
	}
}

void	raydir_calcul(t_cub *t)
{
	if (t->rdr->raydirx < 0)
	{
		t->rdr->stepx = -1;
		t->rdr->sidedistx = (t->ply->posx - t->rdr->mapx) * t->rdr->deltadistx;
	}
	else
	{
		t->rdr->stepx = 1;
		t->rdr->sidedistx = (t->rdr->mapx + 1.0 - t->ply->posx) \
		* t->rdr->deltadistx;
	}
	if (t->rdr->raydiry < 0)
	{
		t->rdr->stepy = -1;
		t->rdr->sidedisty = (t->ply->posy - t->rdr->mapy) * t->rdr->deltadisty;
	}
	else
	{
		t->rdr->stepy = 1;
		t->rdr->sidedisty = (t->rdr->mapy + 1.0 - t->ply->posy) \
		* t->rdr->deltadisty;
	}
}

void	check_hit_wall(t_cub *t)
{
	while (t->rdr->hit == 0)
	{
		if (t->rdr->sidedistx < t->rdr->sidedisty)
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
		if (t->wmap[t->rdr->mapx][t->rdr->mapy] > 0)
			t->rdr->hit = 1;
	}
	if (t->rdr->side == 0)
		t->rdr->perpwalldist = (t->rdr->sidedistx - t->rdr->deltadistx);
	else
		t->rdr->perpwalldist = (t->rdr->sidedisty - t->rdr->deltadisty);
}

void	texture_calcul(t_cub *t)
{
	t->rdr->lineheight = (int)(t->lib->sizey / t->rdr->perpwalldist);
	t->rdr->drawstart = -t->rdr->lineheight / 2 + t->lib->sizey / 2;
	if (t->rdr->drawstart < 0)
		t->rdr->drawstart = 0;
	t->rdr->drawend = t->rdr->lineheight / 2 + t->lib->sizey / 2;
	if (t->rdr->drawend >= t->lib->sizey)
		t->rdr->drawend = t->lib->sizey - 1;
	if (t->rdr->side == 0)
		t->rdr->wallx = t->ply->posy + t->rdr->perpwalldist * t->rdr->raydiry;
	else
		t->rdr->wallx = t->ply->posx + t->rdr->perpwalldist * t->rdr->raydirx;
	t->rdr->wallx -= floor((t->rdr->wallx));
	t->rdr->texx = (int)(t->rdr->wallx * (double)(t->lib->no.w));
	if (t->rdr->side == 0 && t->rdr->raydirx > 0)
		t->rdr->texx = t->lib->no.w - t->rdr->texx - 1;
	if (t->rdr->side == 1 && t->rdr->raydiry < 0)
		t->rdr->texx = t->lib->no.w - t->rdr->texx - 1;
	t->rdr->step = 1.0 * t->lib->no.h / t->rdr->lineheight;
	t->rdr->texpos = (t->rdr->drawstart - t->lib->sizey / 2 + \
		t->rdr->lineheight / 2) * t->rdr->step;
}
