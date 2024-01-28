/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConcreteMateria.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:20:44 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:25:43 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCRETEMATERIA_HPP
#define CONCRETEMATERIA_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"


class ConcreteMateria : public AMateria {
public:
	ConcreteMateria() : AMateria("concrete") {}
	virtual ~ConcreteMateria() {}
	virtual AMateria* clone() const {
		return new ConcreteMateria(*this);
	}
	virtual void use(ICharacter& target) {
		AMateria::use(target); // Call base class implementation for demonstration
	}
};
#endif
