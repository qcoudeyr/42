/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:52 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/25 13:05:27 by  qcoudeyr        ###   ########.fr       */
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
		Point();
		~Point();
		Point &operator=(const Point & other);
		Point (const Point & src);
		Fixed getX();
		Fixed getY();
};

#endif

