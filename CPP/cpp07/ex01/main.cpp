/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:18:17 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/14 14:58:26 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

int main(void)
{
	// Test with an array of integers
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	// Test with an array of doubles
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(doubleArray, 5, print<double>);
	std::cout << std::endl;

	// Test with an array of strings
	std::string stringArray[] = {"apple", "banana", "cherry"};
	iter(stringArray, 3, print<std::string>);
	std::cout << std::endl;

	return 0;
}
