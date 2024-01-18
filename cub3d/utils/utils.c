/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:48:20 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/18 12:28:02 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ply_rt_rgt(t_ply *p)
{
	p->olddirx = p->dirx;
	p->dirx = p->dirx * cos(-p->rspeed) - p->diry * sin(-p->rspeed);
	p->diry = p->olddirx * sin(-p->rspeed) + p->diry * cos(-p->rspeed);
	p->oldplanex = p->planex;
	p->planex = p->planex * cos(-p->rspeed) - p->planey * sin(-p->rspeed);
	p->planey = p->oldplanex * sin(-p->rspeed) + p->planey * cos(-p->rspeed);
}

void	ply_rt_lft(t_ply *p)
{
	p->olddirx = p->dirx;
	p->dirx = p->dirx * cos(p->rspeed) - p->diry * sin(p->rspeed);
	p->diry = p->olddirx * sin(p->rspeed) + p->diry * cos(p->rspeed);
	p->oldplanex = p->planex;
	p->planex = p->planex * cos(p->rspeed) - p->planey * sin(p->rspeed);
	p->planey = p->oldplanex * sin(p->rspeed) + p->planey * cos(p->rspeed);
}

int	keyhandle(int keycode, t_cub *t)
{
	if (keycode == 65307)
		return (closewin(t->lib));
	if (keycode == 65362 || keycode == 119)
		ply_mv_lft(t->ply);
	if (keycode == 97)
		ply_mv_fwd(t->ply);
	if (keycode == 100)
		ply_mv_bwd(t->ply);
	if (keycode == 65364 || keycode == 115)
		ply_mv_rgt(t->ply);
	if (keycode == 65363)
		ply_rt_rgt(t->ply);
	if (keycode == 65361)
		ply_rt_lft(t->ply);
	render(t);
	return (0);
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
