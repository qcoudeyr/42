/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/25 12:13:30 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::~Point()
{
}
Point::Point (Point const & src)
{
	*this = src;
}

Point::Point (const Point & other): _x(other.getX()), _y(other.getY())
{
}

Point& Point::operator=(const Point& other) {
	if (this != &other)
	{
		this->x = other.getX();
		this->y = other.getY();
	}
	return *this;
	}

float Point::getX(){
	return this->_x;
}

float Point::getY(){
	return this->_y;
}
