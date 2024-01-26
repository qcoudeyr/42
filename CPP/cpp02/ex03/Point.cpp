/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/25 16:03:19 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(Fixed x, Fixed y): _x(x), _y(y)
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

Fixed Point::getX() const{
	return _x;
}

Fixed Point::getY() const{
	return _y;
}
