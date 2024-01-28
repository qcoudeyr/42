/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:48:24 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 16:48:25 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & base) : WrongAnimal(base)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = base;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow. Nyan~" << std::endl;
}
