/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:34:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/08 14:16:32 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

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


int worldMap[mapWidth][mapHeight]=
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

void	render(t_cub *t, t_map *m, t_ply *p)
{
	uint32_t	*texture[8];
	uint32_t	buffer[screenHeight][screenWidth];

	for (int i = 0; i < 8; i++) {
	// Calculate the total number of pixels
	size_t numPixels = texWidth * texHeight;
	// Allocate memory for the texture - no need to use calloc as in C++ version we don't initialize either
	texture[i] = (uint32_t*)malloc(numPixels * sizeof(uint32_t));
	}
	for(int x = 0; x < texWidth; x++)
	for(int y = 0; y < texHeight; y++)
	{
	int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
	//int xcolor = x * 256 / texWidth;
	int ycolor = y * 256 / texHeight;
	int xycolor = y * 128 / texHeight + x * 128 / texWidth;
	texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
	texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
	texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
	texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
	texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
	texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
	texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
	texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
	//start the main loop
	int h = texHeight;
	int w = texWidth;
	while(!done())
	{
	for(int x = 0; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		double rayDirX = p->dirX + p->planeX*cameraX;
		double rayDirY = p->dirY + p->planeY*cameraX;

		//which box of the map we're in
		int mapX = (int)(p->posX);
		int mapY = (int)(p->posY);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
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
		//perform DDA
		while (hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
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

		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);


		int pitch = 100;

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2 + pitch;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2 + pitch;
		if(drawEnd >= h) drawEnd = h - 1;

		//texturing calculations
		int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if(side == 0) wallX = p->posY + perpWallDist * rayDirY;
		else          wallX = p->posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int)(wallX * (double)(texWidth));
		if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
		if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

		// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * texHeight / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - pitch - h / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y < drawEnd; y++)
		{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		int texY = (int)texPos & (texHeight - 1);
		texPos += step;
		uint32_t color = texture[texNum][texHeight * texY + texX];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if(side == 1) color = (color >> 1) & 8355711;
		buffer[y][x] = color;
		}
	}

	drawBuffer(buffer[0]);
	for(int y = 0; y < h; y++) for(int x = 0; x < w; x++) buffer[y][x] = 0; //clear the buffer instead of cls()
	//timing for input and FPS counter
	p->oldTime = p->time;
	p->time = getTicks();
	double frameTime = (p->time - p->oldTime) / 1000.0; //frametime is the p->time this frame has taken, in seconds
	print(1.0 / frameTime); //FPS counter
	redraw();

	//speed modifiers
	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
	double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

	/* readKeys();
	//move forward if no wall in front of you
	if(keyDown(SDLK_UP))
	{
		if(worldMap[(int)(p->posX + p->dirX * moveSpeed)][(int)(p->posY)] == 0) p->posX += p->dirX * moveSpeed;
		if(worldMap[(int)(p->posX)][(int)(p->posY + p->dirY * moveSpeed)] == 0) p->posY += p->dirY * moveSpeed;
	}
	//move backwards if no wall behind you
	if(keyDown(SDLK_DOWN))
	{
		if(worldMap[(int)(p->posX - p->dirX * moveSpeed)][(int)(p->posY)] == 0) p->posX -= p->dirX * moveSpeed;
		if(worldMap[(int)(p->posX)][(int)(p->posY - p->dirY * moveSpeed)] == 0) p->posY -= p->dirY * moveSpeed;
	}
	//rotate to the right
	if(keyDown(SDLK_RIGHT))
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
	if(keyDown(SDLK_LEFT))
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = p->dirX;
		p->dirX = p->dirX * cos(rotSpeed) - p->dirY * sin(rotSpeed);
		p->dirY = oldDirX * sin(rotSpeed) + p->dirY * cos(rotSpeed);
		double oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(rotSpeed) - p->planeY * sin(rotSpeed);
		p->planeY = oldPlaneX * sin(rotSpeed) + p->planeY * cos(rotSpeed);
	}
	if(keyDown(SDLK_ESCAPE))
	{
		break;
	} */
	}
	}
}
