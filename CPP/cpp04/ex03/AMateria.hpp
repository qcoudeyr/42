/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:03:12 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:26:46 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
	std::string _type;
public:
	AMateria(std::string const & type) : _type(type) {}
	virtual ~AMateria() {}
	std::string const & getType() const { return _type; }
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

void AMateria::use(ICharacter& target) {
	std::cout << "Using " << _type << " on " << target.getName() << std::endl;
}


#endif
