/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:48:19 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/29 10:45:27 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const & base) : Animal(), Brain()
{
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &base)
	{
		this->_type = base.getType();
		this->brain = base.getBrain();
	}
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & base) {
	if (this != &base)
	{
		this->_type = base.getType();
		for (int i = 0; i < 100; i++)
			this->brain->setIdeas(i, base.getBrain()->getIdea(i));
	}
	return *this;
}

void Dog::setIdeas(std::string str) {
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(i, str);
}

Brain *Dog::getBrain() const {
	return this->brain;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}
