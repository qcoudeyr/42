/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:52 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 13:28:33 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point(Fixed x, Fixed y);
		~Point();
		Point (const Point & src);
		Point& operator=(const Point& other);
		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif

