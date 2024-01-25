/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/25 13:21:14 by  qcoudeyr        ###   ########.fr       */
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

Point::Point (const Point & src): _x(src.getX()), _y(src.getY())
{
}

Point& Point::operator=(const Point& other) {
	if (this != &other)
	{
		this->_x = other.getX();
		this->_y = other.getY();
	}
	return *this;
	}

Fixed Point::getX(){
	return this->_x;
}

Fixed Point::getY(){
	return this->_y;
}
