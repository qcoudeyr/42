/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:18:40 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/25 11:22:54 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _Integer(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const int n)
{
	this->_Integer = n << this->_IntegerBits;
}

Fixed::Fixed(const float n)
{
	this->_Integer = roundf(n * (1 << this->_IntegerBits));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	return (o << rhs.toFloat());
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_Integer = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_Integer);
}

void Fixed::setRawBits(int const raw)
{
	this->_Integer = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_Integer / (1 << this->_IntegerBits));
}

int Fixed::toInt(void) const
{
	return (this->_Integer >> this->_IntegerBits);
}

bool	Fixed::operator>(const Fixed& rhs) const {
	return (this->_IntegerBits > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs) const {
	return (this->_IntegerBits < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs) const {
	return (this->_IntegerBits >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs) const {
	return (this->_IntegerBits <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs) const {
	return (this->_IntegerBits == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs) const {
	return (this->_IntegerBits != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& rhs) const {
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const {
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const {
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const {
	return (this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++()
{
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	return (temp);
}

Fixed& Fixed::operator--()
{
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	return (temp);
}

Fixed &Fixed::max(Fixed & a, Fixed & b){
	return (a > b ? a : b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b){
	return (a > b ? a : b);
}

Fixed &Fixed::min(Fixed & a, Fixed & b){
	return (a < b ? a : b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b){
	return (a < b ? a : b);
}
