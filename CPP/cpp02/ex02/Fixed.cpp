/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:18:40 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/24 22:42:11 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _Integer(0)
{
	std::cout<< "Default constructor called !" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout<< "Destructor called !" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called !" << std::endl;
	this->_Integer = n << this->_IntegerBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called !" << std::endl;
	this->_Integer = roundf(n * (1 << this->_IntegerBits));
}

Fixed::Fixed(Fixed const & src)
{
	std::cout<< "Copy constructor called !" << std::endl;
	*this = src;
}


Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout<< "Copy assignment operator called !" << std::endl;
	if (this != &rhs)
		this->_Integer = rhs.getRawBits();
	return (*this);
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

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_Integer / (1 << this->_IntegerBits));
}

int Fixed::toInt(void) const
{
	return (this->_Integer >> this->_IntegerBits);
}

