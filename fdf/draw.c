/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:19:14 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/18 15:04:24 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void plot(t_data *data, int x, int y, float c)
{
	int	color;

	color = c * 255;
	my_mlx_pixel_put(data, x +(data->win_w / 3), y +(data->win_h / 3), color);
}

int ipart(float x) {
	return (int)floor(x);
}

int ft_round(float x) {
	return ipart(x + 0.5);
}

float fpart(float x) {
	return x - ipart(x);
}

float rfpart(float x) {
	return 1 - fpart(x);
}

void drawLine(t_data *data, int x0, int y0, int x1, int y1)
{
	int steep = abs(y1 - y0) > abs(x1 - x0);

	if (steep) {
		int temp = x0;
		x0 = y0;
		y0 = temp;

		temp = x1;
		x1 = y1;
		y1 = temp;
	}

	if (x0 > x1) {
		int temp = x0;
		x0 = x1;
		x1 = temp;

		temp = y0;
		y0 = y1;
		y1 = temp;
	}

	int dx = x1 - x0;
	int dy = y1 - y0;

	float gradient;
	if (dx == 0) {
		gradient = 1.0;
	} else {
		gradient = (float)dy / (float)dx;
	}

	int xend = ft_round(x0);
	float yend = y0 + gradient * (xend - x0);
	float xgap = rfpart(x0 + 0.5);
	int xpxl1 = xend;
	int ypxl1 = ipart(yend);

	if (steep) {
		plot(data, ypxl1,   xpxl1, rfpart(yend) * xgap);
		plot(data, ypxl1+1, xpxl1, fpart(yend) * xgap);
	} else {
		plot(data, xpxl1, ypxl1,   rfpart(yend) * xgap);
		plot(data, xpxl1, ypxl1+1, fpart(yend) * xgap);
	}

	float intery = yend + gradient;

	xend = ft_round(x1);
	yend = y1 + gradient * (xend - x1);
	xgap = fpart(x1 + 0.5);
	int xpxl2 = xend;
	int ypxl2 = ipart(yend);

	if (steep) {
		plot(data, ypxl2,   xpxl2, rfpart(yend) * xgap);
		plot(data, ypxl2+1, xpxl2, fpart(yend) * xgap);
	} else {
		plot(data, xpxl2, ypxl2, rfpart(yend) * xgap);
		plot(data, xpxl2, ypxl2 + 1, fpart(yend) * xgap);
	}

	int x;
	if (steep) {
		for (x = xpxl1 + 1; x < xpxl2; x++) {
			plot(data, ipart(intery),   x, rfpart(intery));
			plot(data, ipart(intery)+1, x, fpart(intery));
			intery = intery + gradient;
		}
	} else {
		for (x = xpxl1 + 1; x < xpxl2; x++) {
			plot(data, x, ipart(intery),   rfpart(intery));
			plot(data, x, ipart(intery)+1, fpart(intery));
			intery = intery + gradient;
		}
	}
}
