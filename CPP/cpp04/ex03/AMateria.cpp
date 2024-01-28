/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:03:13 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:14:40 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout<< "AMateria Constructor called !"<<std::endl;
}
AMateria::~AMateria()
{
	std::cout<< "AMateria Destructor called !"<<std::endl;
}

AMateria::AMateria(const AMateria& rhs)
{
}


AMateria& AMateria::operator=(const AMateria& rhs) {
	if (this != &rhs){
	}
	return *this;
}

std::string const & AMateria::getType() const
{
	return _type;
}
