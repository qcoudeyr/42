/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:34:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/15 11:59:58 by  qcoudeyr        ###   ########.fr       */
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

void	texture_put(t_cub *t, t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

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

void	dspl_map(t_mlx *lib, t_map *map)
{
	int	v[2];
	int	color;
	int	offset[2];

	v[0] = 7 * (lib->xlen + 1) + 5;
	v[1] = 7 * (lib->ylen + 1) + 5;
	color = tcolor(30, 30, 30);
	offset[0] = 0;
	offset[1] = 0;
 	sqr_print(lib->data, v, offset, color);
	v[0] = 7;
	v[1] = 7;
	offset[0] = map->x +1;
	offset[1] = map->y +1;
	while (map->nx || map->first->ny)
	{
		if (map->value == 0)
			color = trgb(0, 255,255,(255 - map->y));
		else if (map->value == -1)
			color = trgb(100000, 0,0,0);
		else if (map->value == 1)
			color = trgb(0,153, 73, 0);
		else
			color = trgb(0, 0, 255, 0);
		sqr_print(lib->data, v, offset, color);
		if (map->nx)
		{
			map = map->nx;
			offset[0] = (v[0] * map->x) +1;
		}
		else if (map->first->ny)
		{
			map = map->first->ny;
			offset[0] = (v[0] * map->x) +1;
			offset[1] = (v[1] * map->y) +1;
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
void	print_background(t_cub *t)
{
	int y;

	y = 0;
	while(y < t->lib->sizey)
	{
		for(int x = 0; x < t->lib->sizex; x++)
		{
			if (y < (t->lib->sizey / 2))
				pixel_put(t->lib->data, x, y, trgb(80, t->lib->ceiling[0], t->lib->ceiling[1], t->lib->ceiling[2]));
			else
				pixel_put(t->lib->data, x, y, trgb(80, t->lib->floor[0], t->lib->floor[1], t->lib->floor[2]));
		}
		y++;
	}
}

void	draw_texture(t_cub *t)
{
	t->rdr->y = t->rdr->drawStart;
	while (t->rdr->y < t->rdr->drawEnd)
	{
		t->rdr->texY = (int)t->rdr->texPos & (t->texH - 1);
		t->rdr->texPos += t->rdr->step;
		if (t->rdr->side == 0)
		{
			if (t->rdr->rayDirX < 0)
				t->rdr->color = get_pixel\
(t->lib->we.ptr, t->rdr->texX - t->test, t->rdr->texY);
			else
				t->rdr->color = get_pixel(t->lib->ea.ptr, t->rdr->texX,t->rdr->texY);
		}
		else if (t->rdr->side == 1)
		{
			if (t->rdr->rayDirY > 0)
				t->rdr->color = get_pixel(t->lib->so.ptr, t->rdr->texX,t->rdr->texY);
			else
				t->rdr->color = get_pixel(t->lib->no.ptr, t->rdr->texX,t->rdr->texY);
		}
		if(t->rdr->side == 1)
			t->rdr->color = (t->rdr->color >> 1) & 8355711;
		texture_put(t, t->lib->data, t->rdr->x, t->rdr->y++, t->rdr->color);
	}
}

int	render(t_cub *t)
{
	t->rdr->x = 0;
	while (t->rdr->x < t->lib->sizex)
	{
		t->rdr->cameraX = 2 * t->rdr->x / (double)t->lib->sizex - 1; //t->rdr->x-coordinate in camera space
		t->rdr->rayDirX = t->ply->dirX + t->ply->planeX * t->rdr->cameraX;
		t->rdr->rayDirY = t->ply->dirY + t->ply->planeY * t->rdr->cameraX;
		t->rdr->mapX = (int)t->ply->posX;
		t->rdr->mapY = (int)t->ply->posY;
		t->rdr->deltaDistX = (t->rdr->rayDirX == 0) ? 1e30 : ft_abs(1 / t->rdr->rayDirX);
		t->rdr->deltaDistY = (t->rdr->rayDirY == 0) ? 1e30 : ft_abs(1 / t->rdr->rayDirY);
		t->rdr->hit = 0;
		if(t->rdr->rayDirX < 0)
		{
			t->rdr->stepX = -1;
			t->rdr->sideDistX = (t->ply->posX - t->rdr->mapX) * t->rdr->deltaDistX;
		}
		else
		{
			t->rdr->stepX = 1;
			t->rdr->sideDistX = (t->rdr->mapX + 1.0 - t->ply->posX) * t->rdr->deltaDistX;
		}
		if(t->rdr->rayDirY < 0)
		{
			t->rdr->stepY = -1;
			t->rdr->sideDistY = (t->ply->posY - t->rdr->mapY) * t->rdr->deltaDistY;
		}
		else
		{
			t->rdr->stepY = 1;
			t->rdr->sideDistY = (t->rdr->mapY + 1.0 - t->ply->posY) * t->rdr->deltaDistY;
		}
		while(t->rdr->hit == 0)
		{
			if(t->rdr->sideDistX < t->rdr->sideDistY)
			{
				t->rdr->sideDistX += t->rdr->deltaDistX;
				t->rdr->mapX += t->rdr->stepX;
				t->rdr->side = 0;
			}
			else
			{
				t->rdr->sideDistY += t->rdr->deltaDistY;
				t->rdr->mapY += t->rdr->stepY;
				t->rdr->side = 1;
			}
			if(worldMap[mapX][mapY] > 0)
				t->rdr->hit = 1;
		}
		if(t->rdr->side == 0)
			t->rdr->perpWallDist = (t->rdr->sideDistX - t->rdr->deltaDistX);
		else
			t->rdr->perpWallDist = (t->rdr->sideDistY - t->rdr->deltaDistY);
		t->rdr->lineHeight = (int)(t->lib->sizey / t->rdr->perpWallDist);
		t->rdr->drawStart = -t->rdr->lineHeight / 2 + t->lib->sizey / 2;
		if(t->rdr->drawStart < 0) t->rdr->drawStart = 0;
		t->rdr->drawEnd = t->rdr->lineHeight / 2 + t->lib->sizey / 2;
		if(t->rdr->drawEnd >= t->lib->sizey) t->rdr->drawEnd = t->lib->sizey - 1;
		if (t->rdr->side == 0)
			t->rdr->wallX = t->ply->posY + t->rdr->perpWallDist * t->rdr->rayDirY;
		else
			t->rdr->wallX = t->ply->posX + t->rdr->perpWallDist * t->rdr->rayDirX;
		t->rdr->wallX -= floor((t->rdr->wallX));
		t->rdr->texX = (int)(t->rdr->wallX * (double)(t->lib->no.w));
		if(t->rdr->side == 0 && t->rdr->rayDirX > 0)
			t->rdr->texX = t->lib->no.w - t->rdr->texX - 1;
		if(t->rdr->side == 1 && t->rdr->rayDirY < 0)
			t->rdr->texX = t->lib->no.w - t->rdr->texX - 1;
		t->rdr->step = 1.0 * t->lib->no.h / t->rdr->lineHeight;
		t->rdr->texPos = (t->rdr->drawStart - t->lib->sizey / 2 + t->rdr->lineHeight / 2) * t->rdr->step;
		draw_texture(t);
		t->rdr->x++;
	}
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
	dspl_map(t->lib, origin_map(t->lib->map));
	return (0);
}
