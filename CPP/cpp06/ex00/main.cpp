/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:18:17 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 21:05:05 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [input]" << std::endl;
		return (0);
	}
	ScalarConverter::convert(std::string(argv[1]));

	return EXIT_SUCCESS;
}
