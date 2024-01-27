/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:44:09 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 13:19:38 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default WrongAnimal")
{
	std::cout<<"WrongAnimal constructor called !"<<std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal destructor called !"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	 type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout<< "Wesh Alors, J'suis dans le Game en Claquette"<<std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
