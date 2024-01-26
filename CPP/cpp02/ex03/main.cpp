/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:18:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 15:31:20 by  qcoudeyr        ###   ########.fr       */
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

	a = a.SetPointValue(Fixed(25.0f), Fixed(25.0f));
	b = b.SetPointValue(Fixed(42.0f), Fixed(42.0f));
	c = c.SetPointValue(Fixed(30.0f), Fixed(2.0f));
	testPoint = testPoint.SetPointValue(Fixed(0.5f), Fixed(0.5f));

	bool isInside = bsp(a, b, c, testPoint);

	if (isInside)
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is not inside the triangle." << std::endl;

	testPoint = testPoint.SetPointValue(Fixed(26.0f), Fixed(25.0f));

	isInside = bsp(a, b, c, testPoint);
	if (isInside)
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is not inside the triangle." << std::endl;

	return 0;
}
