/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/25 11:44:17 by  qcoudeyr        ###   ########.fr       */
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

Point &operator=(const Point& other)
{
	if (this != &other)
		this->x = other.x; this->y = other.y;
	return *this;
}
