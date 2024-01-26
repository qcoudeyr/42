/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:18:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 14:19:39 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main()
{
	Point a(25.0f, 25.0f);
	Point b(42.0f, 42.0f);
	Point c(30.0f, 2.0f);

	Point testPoint(0.5f, 0.5f);

	bool isInside = bsp(a, b, c, testPoint);

	if (isInside)
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is not inside the triangle." << std::endl;

	return 0;
}
