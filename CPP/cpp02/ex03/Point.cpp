/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 14:54:42 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(Fixed x, Fixed y): _x(0), _y(0)
{
}

Point::~Point()
{
}

Point::Point (const Point & src): _x(src.getX()), _y(src.getY())
{
}

Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return *this;
	return *this;
}

void Point::setValue(float xValue, float yValue)
{
	this->_x.setRawBits(value);
}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}
