/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:48:20 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/10 15:18:10 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


static int worldMap[24][24]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

void	ply_mov(t_ply *p, int keycode)
{
	//speed modifiers
	double moveSpeed = (p->frameTime + 0.1) *2; //the constant value is in squares/second
	double rotSpeed = p->frameTime; //the constant value is in radians/second
	//move forward if no wall in front of you
	if(keycode == 65362)
	{
		if(worldMap[(int)(p->posX + p->dirX * moveSpeed)][(int)(p->posY)] == 0) p->posX += p->dirX * moveSpeed;
		if(worldMap[(int)(p->posX)][(int)(p->posY + p->dirY * moveSpeed)] == 0) p->posY += p->dirY * moveSpeed;
	}
	//move backwards if no wall behind you
	if(keycode == 65364)
	{
		if(worldMap[(int)(p->posX - p->dirX * moveSpeed)][(int)(p->posY)] == 0) p->posX -= p->dirX * moveSpeed;
		if(worldMap[(int)(p->posX)][(int)(p->posY - p->dirY * moveSpeed)] == 0) p->posY -= p->dirY * moveSpeed;
	}
	//rotate to the right
	if(keycode == 65363)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = p->dirX;
		p->dirX = p->dirX * cos(-rotSpeed) - p->dirY * sin(-rotSpeed);
		p->dirY = oldDirX * sin(-rotSpeed) + p->dirY * cos(-rotSpeed);
		double oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(-rotSpeed) - p->planeY * sin(-rotSpeed);
		p->planeY = oldPlaneX * sin(-rotSpeed) + p->planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if(keycode == 65361)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = p->dirX;
		p->dirX = p->dirX * cos(rotSpeed) - p->dirY * sin(rotSpeed);
		p->dirY = oldDirX * sin(rotSpeed) + p->dirY * cos(rotSpeed);
		double oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(rotSpeed) - p->planeY * sin(rotSpeed);
		p->planeY = oldPlaneX * sin(rotSpeed) + p->planeY * cos(rotSpeed);
	}
}

int	keyhandle(int keycode, t_cub *t)
{
	ft_printf("%i\n", keycode);
	if (keycode == 65307)
		return (closewin(t->lib));
	else
	{
		if (keycode <= 65364 && keycode >= 65361)
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
