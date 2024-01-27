/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:15:07 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 13:17:13 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat()
{
	Animal::type = "WrongCat";
	std::cout<<"WrongCat constructor called !"<<std::endl;
}
WrongCat::~WrongCat()
{
	std::cout<<"WrongCat destructor called !"<<std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	 type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void makeSound()
{
	std::cout<<"Miaou Miaou"<<std::endl;
}
