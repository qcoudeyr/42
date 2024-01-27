/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:48:35 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 16:54:15 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const & base) : Animal(), Brain()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = base;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdeas(std::string str) {
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(i, str);
}

Brain *Cat::getBrain() const {
	return this->brain;
}
