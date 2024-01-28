/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:42:28 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 15:05:02 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {

	//	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const & base) : AMateria(Cure()){
//	std::cout << "Cure copy constructor called" << std::endl;
	*this = base;
}

Cure::~Cure() {

	//	std::cout << "Cure destructor called" << std::endl;
}

Cure & Cure::operator=(Cure const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
