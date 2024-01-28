/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:38:24 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 13:36:37 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_Ideas[i] = other._Ideas[i];
	}
}


Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(Brain const & base) {
	if (this != &base)
	{
		for (int i = 0; i < 100; i++)
			this->_Ideas[i] = base.getIdea(i);
	}
	return *this;
}

void Brain::setIdeas(int i, std::string value)
{
	this->_Ideas[i] = value;
}

std::string Brain::getIdea(int i) const {
	return _Ideas[i];
}
