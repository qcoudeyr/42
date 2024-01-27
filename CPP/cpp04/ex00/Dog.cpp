/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:41:22 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 10:58:13 by  qcoudeyr        ###   ########.fr       */
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

void makeSound()
{
	std::cout<<"Dog : *Woauf*"<<std::endl;
}
