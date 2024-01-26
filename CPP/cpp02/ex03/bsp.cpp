/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:51 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 14:33:10 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float sign(Point p1, Point p2, Point p3)
{
	Fixed x, y;
	float x1, y1, x2, y2, x3, y3;
	x1 = p1.getX().toFloat();
	y1 = p1.getY().toFloat();
	x2 = p2.getX().toFloat();
	y2 = p2.getY().toFloat();
	x3 = p3.getX().toFloat();
	y3 = p3.getY().toFloat();
	return ((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
