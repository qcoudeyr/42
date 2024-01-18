/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ply_mvm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:22:15 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/18 12:27:51 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ply_mv_lft(t_ply *p)
{
	if (p->wmap[(int)(p->posx + p->dirx * p->mspeed)][(int)(p->posy)] == 0)
		p->posx += p->dirx * p->mspeed;
	if (p->wmap[(int)(p->posx)][(int)(p->posy + p->diry * p->mspeed)] == 0)
		p->posy += p->diry * p->mspeed;
}

void	ply_mv_fwd(t_ply *p)
{
	if (p->wmap[(int)(p->posx - (p->diry * p->mspeed))][(int)(p->posy)] == 0)
		p->posx -= p->diry * p->mspeed;
	if (p->wmap[(int)(p->posx)][(int)(p->posy + (p->dirx * p->mspeed))] == 0)
		p->posy += p->dirx * p->mspeed;
}

void	ply_mv_bwd(t_ply *p)
{
	if (p->wmap[(int)(p->posx)][(int)(p->posy + (p->diry * p->mspeed))] == 0)
		p->posx += p->diry * p->mspeed;
	if (p->wmap[(int)(p->posx)][(int)(p->posy - (p->dirx * p->mspeed))] == 0)
		p->posy -= p->dirx * p->mspeed;
}

void	ply_mv_rgt(t_ply *p)
{
	if (p->wmap[(int)(p->posx - p->dirx * p->mspeed)][(int)(p->posy)] == 0)
		p->posx -= p->dirx * p->mspeed;
	if (p->wmap[(int)(p->posx)][(int)(p->posy - p->diry * p->mspeed)] == 0)
		p->posy -= p->diry * p->mspeed;
}
