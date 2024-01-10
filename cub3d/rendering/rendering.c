/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:34:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/10 19:07:12 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


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
}

void	dspl_map(t_mlx *lib, t_map *map)
{
	int	v[2];
	int	color;
	int	offset[2];

	v[0] = 10 * (lib->xlen + 1) + 5;
	v[1] = 10 * (lib->ylen + 1) + 5;
	color = tcolor(30, 30, 30);
	offset[0] = lib->offset[0] - 6;
	offset[1] = lib->offset[1] - 6;
	sqr_print(lib->data, v, offset, color);
	v[0] = 10;
	v[1] = 10;
	offset[0] = lib->offset[0] + map->x +1;
	offset[1] = lib->offset[1] + map->y +1;
	while (map->nx || map->first->ny)
	{
		if (map->value == 0)
			color = tcolor(255,255,(255 - map->y));
		else if (map->value == -1)
			color = tcolor(30, 30, 30);
		else if (map->value == 1)
			color = tcolor(153, 73, 0);
		else
			color = tcolor(0, 255, 0);
		sqr_print(lib->data, v, offset, color);
		if (map->nx)
		{
			map = map->nx;
			offset[0] = lib->offset[0] + (v[0] * map->x) +1;
		}
		else if (map->first->ny)
		{
			map = map->first->ny;
			offset[0] = lib->offset[0] + (v[0] * map->x) +1;
			offset[1] = lib->offset[1] + (v[1] * map->y) +1;
		}
		else
			map = map->first->ny;
	}
	if (!map->nx && map)
		sqr_print(lib->data, v, offset, color);
	mlx_put_image_to_window(lib->mlx, lib->c_win, lib->data->img, 0, 0);
	return;
}

double	ft_abs(double i)
{
	if (i < 0)
		return (double)(i * (double)-1);
	else
		return (i);
}

unsigned long getTicks(t_cub *t)
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

int	verLine(t_mlx *lib, int buffer[lib->sizex][lib->sizey])
{
	int	h,w;

	h = lib->sizey;
	w = lib->sizex;
	for (int y = 0; y <= h; y++)
	{
		for (int x = 0; x <= w; x++)
			pixel_put(lib->data, x, y, buffer[x][y]);
	}
	return 1;
	}

int	render(t_cub *t)
{
	int	buffer[t->lib->sizey][t->lib->sizex];

	for(int y = 0; y < t->lib->sizey; y++)
	{
		for(int x = 0; x < t->lib->sizex; x++)
		{
			if (y < (t->lib->sizey / 2))
				pixel_put(t->lib->data, x, y, trgb(80, t->lib->ceiling[0], t->lib->ceiling[1], t->lib->ceiling[2]));
			else
				pixel_put(t->lib->data, x, y, trgb(80, t->lib->floor[0], t->lib->floor[1], t->lib->floor[2]));
		}
	}
	for(int x = 0; x < t->lib->sizex; x++)
	{
		double cameraX = 2 * x / (double)t->lib->sizex - 1; //x-coordinate in camera space
		double rayDirX = t->ply->dirX + t->ply->planeX * cameraX;
		double rayDirY = t->ply->dirY + t->ply->planeY * cameraX;
		int mapX = (int)t->ply->posX;
		int mapY = (int)t->ply->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1 / rayDirY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (t->ply->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - t->ply->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (t->ply->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - t->ply->posY) * deltaDistY;
		}
		while(hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if(worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(t->lib->sizey / perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + t->lib->sizey / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + t->lib->sizey / 2;
		if(drawEnd >= t->lib->sizey) drawEnd = t->lib->sizey - 1;

		int texNum = worldMap[mapX][mapY] - 1;

		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (side == 0)
			wallX = t->ply->posY + perpWallDist * rayDirY;
		else
			wallX = t->ply->posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int)(wallX * (double)(t->lib->no.w));
		if(side == 0 && rayDirX > 0) texX = t->lib->no.w - texX - 1;
		if(side == 1 && rayDirY < 0) texX = t->lib->no.w - texX - 1;
		double step = 1.0 * t->lib->no.h / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - t->lib->sizey / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y<drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (t->lib->no.h - 1);
			texPos += step;
			unsigned int color;
			(void)texY;
			if (texNum != 0)
				color = trgb(0, 255, 0, 0);/* t->lib->no.ptr. + (t->lib->no.h * texY + texX); */
			if(side == 1)
				color = (color >> 1) & 8355711;
			buffer[y][x] = color;
		}
	}
	(void)buffer;
	//timing for input and FPS counter
	t->ply->oldTime = t->ply->time;
	t->ply->time = getTicks(t);
	if (t->ply->oldTime == 0)
		t->ply->oldTime = t->ply->time;
	t->ply->frameTime = (t->ply->time - t->ply->oldTime) / 1000;
	ft_printf("%i\n", t->ply->frameTime);
	//print(1.0 / frameTime); //FPS counter
	mlx_clear_window(t->lib->mlx, t->lib->c_win);
	mlx_put_image_to_window(t->lib->mlx, t->lib->c_win, t->lib->data->img, 0 , 0);
	mlx_string_put(t->lib->mlx, t->lib->c_win, 10, 10, tcolor(255,255,255), ft_itoa(t->ply->frameTime));
	return (0);
}
