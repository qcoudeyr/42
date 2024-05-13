/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:56:28 by shiro             #+#    #+#             */
/*   Updated: 2024/05/12 21:05:02 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &) {}

ScalarConverter	& ScalarConverter::operator=(ScalarConverter const &)
{
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string input)
{
	double value = std::strtod(input.c_str(), NULL);
	char c = static_cast<char>(value);
//Char
	if (std::isnan(value) || std::isinf(value) || value < CHAR_MIN || value > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
 else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
//Int
	if (std::isnan(value) || std::isinf(value) || value > (float)INT_MAX || value < (float)INT_MIN)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
//Float
	std::cout << "float: " << value << 'f' << std::endl;
//Double
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}
