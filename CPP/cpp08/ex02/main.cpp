/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:18:17 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/14 15:05:33 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main (void)
{
	// Test default constructor
	Array<int> arr1;
	std::cout << "arr1 size: " << arr1.size() << std::endl;

	// Test constructor with size parameter
	Array<int> arr2(5);
	std::cout << "Value in array 2: ";
	for (unsigned int i = 0; i < arr2.size(); ++i) {
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	// Test copy constructor and assignment operator
	Array<int> arr3 = arr2;
	arr3[0] = 10;
	std::cout << "arr2[0]: " << arr2[0] << std::endl; // Should still be the default value
	std::cout << "arr3[0]: " << arr3[0] << std::endl;

	// Test subscript operator with out-of-range index
	try {
		std::cout << arr2[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
