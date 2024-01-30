/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:48:35 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/29 10:46:31 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat & base) : Animal(base), brain(new Brain(*base.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	if (this->brain)
		delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const & base)
{
	if (this != &base)
	{
		this->_type = base.getType();
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*base.getBrain());
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}

void Cat::setIdeas(std::string str)
{
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(i, str);
}

Brain* Cat::getBrain() const {
	return this->brain;
}
