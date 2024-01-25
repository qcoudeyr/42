/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:18:40 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/24 22:33:22 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _Integer(0)
{
	std::cout<< "Default constructor called !" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout<< "Copy constructor called !" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout<< "Destructor called !" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
		std::cout<< "Copy assignment operator called !" << std::endl;
	if (this != &rhs)
		this->_Integer = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called !" << std::endl;
	return (this->_Integer);
}

void Fixed::setRawBits(int const raw)
{
	this->_Integer = raw;
}

