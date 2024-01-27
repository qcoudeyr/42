/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:48:19 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 16:54:30 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const & base) : Animal(base)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = base;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

void Dog::setIdeas(std::string str) {
	for (int i = 0; i < 100; i++)
		this->_brain->setIdeas(i, str);
}

Brain *Dog::getBrain() const {
	return this->_brain;
}

void Dog::makeSound() const {
	std::cout << "Woof. Graou~" << std::endl;
}
