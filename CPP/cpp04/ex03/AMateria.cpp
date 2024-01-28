/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:03:13 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 15:04:45 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
//	std::cout << "AMateria default constructor called" << std::endl;
	this->_type = "";
}

AMateria::AMateria(std::string const & _type) {
//	std::cout << "AMateria string constructor called" << std::endl;
	this->_type = _type;
}

AMateria::AMateria(AMateria const & base) {
//	std::cout << "AMateria copy constructor called" << std::endl;
	*this = base;
}

AMateria::~AMateria() {
/* //	std::cout << "AMateria destructor called" << std::endl; */
}


AMateria & AMateria::operator=(AMateria const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}


std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void) target;
}
