/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:18:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 15:06:25 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main()
{
	Point a;
	Point b;
	Point c;
	Point testPoint;

	a.SetPointValue(25.0f, 25.0f);
	b.SetPointValue(42.0f, 42.0f);
	c.SetPointValue(30.0f, 2.0f);
	testPoint.SetPointValue(0.5f, 0.5f);

	bool isInside = bsp(a, b, c, testPoint);

	if (isInside)
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is not inside the triangle." << std::endl;

	testPoint.SetPointValue(26.0f, 25.0f);

	isInside = bsp(a, b, c, testPoint);
	if (isInside)
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is not inside the triangle." << std::endl;

	return 0;
}
