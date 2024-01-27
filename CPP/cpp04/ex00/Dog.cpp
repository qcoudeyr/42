/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:41:22 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 13:20:22 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	Animal::type = "Dog";
	std::cout<<"Dog constructor called !"<<std::endl;
}
Dog::~Dog()
{
	std::cout<<"Dog destructor called !"<<std::endl;
}

Dog::Dog(const Dog& other) {
	 type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other) {
		type = other.type;
	}
	return *this;
}


void makeSound()
{
	std::cout<<"Dog : *Woauf*"<<std::endl;
}
