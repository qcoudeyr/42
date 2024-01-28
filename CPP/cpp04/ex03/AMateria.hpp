/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:03:12 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:59:22 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <iomanip>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const & _type);
		AMateria(AMateria const & base);
		virtual ~AMateria();

		AMateria & operator=(AMateria const & base);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif

