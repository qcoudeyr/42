/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:41:18 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 10:57:48 by  qcoudeyr        ###   ########.fr       */
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

void makeSound()
{
	std::cout<<"Cat : *Meow~Meow~*"<<std::endl;
}
