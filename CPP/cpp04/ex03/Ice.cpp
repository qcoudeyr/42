/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:42:46 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 15:05:10 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {

	//	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const & base) : AMateria(Ice()){

	//	std::cout << "Ice copy constructor called" << std::endl;
	*this = base;
}

Ice::~Ice() {

	//	std::cout << "Ice destructor called" << std::endl;
}


Ice & Ice::operator=(Ice const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
