/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:18:41 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/25 11:22:36 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _Integer;
		const static int _IntegerBits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(Fixed const & src);
		Fixed & operator=(Fixed const & rhs);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const & max(Fixed const &a, Fixed const &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const & min(Fixed const &a, Fixed const &b);
};

	std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
	std::ostream & operator>(std::ostream & o, Fixed const & rhs);
	std::ostream & operator<(std::ostream & o, Fixed const & rhs);
	std::ostream & operator>=(std::ostream & o, Fixed const & rhs);
	std::ostream & operator<=(std::ostream & o, Fixed const & rhs);
	std::ostream & operator==(std::ostream & o, Fixed const & rhs);
	std::ostream & operator!=(std::ostream & o, Fixed const & rhs);
	std::ostream & operator+(std::ostream & o, Fixed const & rhs);
	std::ostream & operator-(std::ostream & o, Fixed const & rhs);
	std::ostream & operator*(std::ostream & o, Fixed const & rhs);
	std::ostream & operator/(std::ostream & o, Fixed const & rhs);

#endif

