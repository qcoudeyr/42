/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:48:20 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/15 17:32:39 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ply_mov(t_ply *p, int keycode)
{
	double movespeed = 0.12;
	double rotspeed = 0.12;

	if(keycode == 65362 || keycode == 119)
	{
		if(p->wmap[(int)(p->posx + p->dirx * movespeed)][(int)(p->posy)] == 0)
			p->posx += p->dirx * movespeed;
		if(p->wmap[(int)(p->posx)][(int)(p->posy + p->diry * movespeed)] == 0)
			p->posy += p->diry * movespeed;
	}
	if(keycode == 97)
	{
		if(p->wmap[(int)(p->posx - (p->diry * movespeed))][(int)(p->posy)] == 0)
			p->posx -= p->diry * movespeed;
		if(p->wmap[(int)(p->posx)][(int)(p->posy + (p->dirx * movespeed))] == 0)
			p->posy += p->dirx * movespeed;

	}
	if(keycode == 100)
	{
		if(p->wmap[(int)(p->posx)][(int)(p->posy + (p->diry * movespeed))] == 0)
			p->posx += p->diry * movespeed;
		if(p->wmap[(int)(p->posx)][(int)(p->posy - (p->dirx * movespeed))] == 0)
			p->posy -= p->dirx * movespeed;
	}
	if(keycode == 65364 || keycode == 115)
	{
		if(p->wmap[(int)(p->posx - p->dirx * movespeed)][(int)(p->posy)] == 0)
			p->posx -= p->dirx * movespeed;
		if(p->wmap[(int)(p->posx)][(int)(p->posy - p->diry * movespeed)] == 0)
			p->posy -= p->diry * movespeed;
	}
	//rotate to the right
	if(keycode == 65363)
	{
		//both camera direction and camera plane must be rotated
		p->olddirx = p->dirx;
		p->dirx = p->dirx * cos(-rotspeed) - p->diry * sin(-rotspeed);
		p->diry = p->olddirx * sin(-rotspeed) + p->diry * cos(-rotspeed);
		p->oldplanex = p->planex;
		p->planex = p->planex * cos(-rotspeed) - p->planey * sin(-rotspeed);
		p->planey = p->oldplanex * sin(-rotspeed) + p->planey * cos(-rotspeed);
	}
	if(keycode == 65361)
	{
		p->olddirx = p->dirx;
		p->dirx = p->dirx * cos(rotspeed) - p->diry * sin(rotspeed);
		p->diry = p->olddirx * sin(rotspeed) + p->diry * cos(rotspeed);
		p->oldplanex = p->planex;
		p->planex = p->planex * cos(rotspeed) - p->planey * sin(rotspeed);
		p->planey = p->oldplanex * sin(rotspeed) + p->planey * cos(rotspeed);
	}
}

int	keyhandle(int keycode, t_cub *t)
{
	if (keycode == 65307)
		return (closewin(t->lib));
	else
	{
		if(keycode == 65451)
			t->test += 1;
		if(keycode == 65453)
			t->test -= 1;
		if ((keycode <= 65364 && keycode >= 65361) || (keycode < 120 && keycode > 80))
			ply_mov(t->ply, keycode);
		render(t);
	}
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_mlx *lib)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		if (lib->scale[0] > 2 && lib->scale[1] > 2)
		{
			lib->scale[0] = 0.90 * (double)lib->scale[0];
			lib->scale[1] = 0.90 * (double)lib->scale[1];
		}
	}
	else if (button == 5)
	{
		if (lib->scale[0] < 10 && lib->scale[1] < 10)
		{
			lib->scale[0] += 1;
			lib->scale[1] += 1;
		}
		else
		{
			lib->scale[0] = 1.2 * (double)lib->scale[0];
			lib->scale[1] = 1.2 * (double)lib->scale[1];
		}
	}
	return (0);
}

void	utils_init(t_utils *u)
{
	u->i = 0;
	u->x = 0;
	u->y = 0;
	u->z = 0;
	u->c = 0;
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

t_utils	*utils_free(t_utils *u)
{
	if (u->tmp1 != NULL)
		u->tmp1 = pfree(u->tmp1);
	if (u->tmp2 != NULL)
		u->tmp2 = pfree(u->tmp2);
	if (u->str1 != NULL)
		u->str1 = pfree(u->str1);
	if (u->str2 != NULL)
		u->str2 = pfree(u->str2);
	if (u->lst != NULL)
		u->lst = pfree(u->lst);
	if (u->tab != NULL)
		u->tab = tabfree((void **)u->tab);
	if (u->ptr != NULL)
		u->ptr = pfree(u->ptr);
	if (u->ptr1 != NULL)
		u->ptr1 = pfree(u->ptr1);
	if (u->ptr2 != NULL)
		u->ptr2 = pfree(u->ptr2);
	if (u->lstptr != NULL)
		u->lstptr = tabfree(u->lstptr);
	u = pfree(u);
	return (u);
}
