/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:48:20 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/09 16:30:50 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
/*
void	ply_mov(t_cub *t)
{
	//speed modifiers
	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
	double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
	//move forward if no wall in front of you
	if(keyDown(SDLK_UP))
	{
		if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
	}
	//move backwards if no wall behind you
	if(keyDown(SDLK_DOWN))
	{
		if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
	}
	//rotate to the right
	if(keyDown(SDLK_RIGHT))
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if(keyDown(SDLK_LEFT))
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
}
 */
int	keyhandle(int keycode, t_mlx *lib)
{
	ft_printf("%i\n", keycode);
	if (keycode == 65307)
		return (closewin(lib));
	else
	{
		if (keycode == 65364) //Down
			lib->offset[0] += 10;
		if (keycode == 65362) //Up
			lib->offset[0] -= 10;
		if (keycode == 65363) // Right
			lib->offset[1] += 10;
		if (keycode == 65361) // Left
			lib->offset[1] -= 10;
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
