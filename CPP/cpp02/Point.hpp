/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:52 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/25 11:51:42 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

class Point
{
private:
	float _x;
	float _y;
public:
	Point();
	~Point();
	Point (const Point&);
	Point &operator=(const Point & other);
	float getX();
	float getY();
};

#endif

