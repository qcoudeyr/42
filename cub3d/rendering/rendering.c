/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:34:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/10 08:49:16 by  qcoudeyr        ###   ########.fr       */
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

int	ft_abs(double i)
{
	if (i < 0)
		return (i * -1);
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
		t->init_t = (tv.tv_sec * 1000UL + tv.tv_usec / 1000UL);
	return (unsigned long)(tv.tv_sec * 1000UL + tv.tv_usec / 1000UL);
}

int	verLine(t_mlx *lib, int x, int y1, int y2, int color)
{
	int h = lib->sizey;
	int w = lib->sizex;


	// Swap y1 and y2 if necessary
	if (y2 < y1) {
		int temp = y1;
		y1 = y2;
		y2 = temp;
	}

	// Clipping and validation checks
	if (y2 < 0 || y1 >= h || x < 0 || x >= w) return 0; //no single point of the line is on screen
	if (y1 < 0) y1 = 0; //clip
	if (y2 >= h) y2 = h - 1; //clip

	// Draw the line
	for (int y = y1; y <= y2; y++) {
		pixel_put(lib->data, x, y, color);
	}
	return 1;
	}

void	render(t_cub *t, t_ply *p)
{

	for(int x = 0; x < t->lib->sizex; x++)
	{
		double cameraX = 2 * x / (double)t->lib->sizex - 1; //x-coordinate in camera space
		double rayDirX = p->dirX + p->planeX * cameraX;
		double rayDirY = p->dirY + p->planeY * cameraX;
		int mapX = (int)(p->posX);
		int mapY = (int)(p->posY);

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
		sideDistX = (p->posX - mapX) * deltaDistX;
		}
		else
		{
		stepX = 1;
		sideDistX = (mapX + 1.0 - p->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
		stepY = -1;
		sideDistY = (p->posY - mapY) * deltaDistY;
		}
		else
		{
		stepY = 1;
		sideDistY = (mapY + 1.0 - p->posY) * deltaDistY;
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
		//Check if ray has hit a wall
		if(worldMap[mapX][mapY] > 0) hit = 1;
		}
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(t->lib->sizey / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + t->lib->sizey / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + t->lib->sizey / 2;
		if(drawEnd >= t->lib->sizey) drawEnd = t->lib->sizey - 1;

		//choose wall color
		int color;
		switch(worldMap[mapX][mapY])
		{
		case 1:  color = tcolor(255,0,0);    break; //red
		case 2:  color = tcolor(0,255,0);  break; //green
		case 3:  color = tcolor(  0,   0, 255);   break; //blue
		case 4:  color = tcolor(  0, 255, 255);  break; //white
		default: color = tcolor(255,   0, 255); break; //yellow
		}

		//give x and y sides different brightness
		if(side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		verLine(t->lib, x, drawStart, drawEnd, color);
	}
	//timing for input and FPS counter
	p->oldTime = p->time;
	p->time = getTicks(t);
	p->frameTime = (p->time - p->oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
	ft_printf("%i\n", p->frameTime);
	mlx_string_put(t->lib->mlx, t->lib->c_win, 10, 10, tcolor(255,255,255), ft_itoa(p->frameTime));
	//print(1.0 / frameTime); //FPS counter
	mlx_clear_window(t->lib->mlx, t->lib->c_win);
	mlx_put_image_to_window(t->lib->mlx, t->lib->c_win, t->lib->data->img, 0 , 0);
}
