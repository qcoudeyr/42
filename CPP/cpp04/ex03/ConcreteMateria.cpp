/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConcreteMateria.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:20:41 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:24:24 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConcreteMateria.hpp"

ConcreteMateria::ConcreteMateria() : AMateria("concrete")
{

}

ConcreteMateria::~ConcreteMateria(){
}

ConcreteMateria::AMateria* clone() const 
{
	return new ConcreteMateria(*this);
}

void ConcreteMateria::use(ICharacter& target)
{
}
