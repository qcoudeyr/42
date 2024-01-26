/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 15:10:47 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::	Point() : _x(0), _y(0){
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {

}

Point::~Point(){
}

Point::Point (const Point & src): _x(src.getX()), _y(src.getY())
{
}

Point& Point::operator=(const Point& other)
{
	(void) other;
	return *this;
}

Point Point::SetPointValue(Fixed newX, Fixed newY) const{
		return Point(newX, newY);
}


Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}
