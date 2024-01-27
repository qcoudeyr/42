/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:41:18 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 13:14:40 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	Animal::type = "Cat";
	std::cout<<"Cat constructor called !"<<std::endl;
}
Cat::~Cat()
{
	std::cout<<"Cat destructor called !"<<std::endl;
}

Cat::Cat(const Cat& other) {
	 type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void makeSound()
{
	std::cout<<"Cat : *Meow~Meow~*"<<std::endl;
}
