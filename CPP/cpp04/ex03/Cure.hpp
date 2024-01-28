/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:42:38 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:42:40 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:

	public:
		Cure();
		Cure(Cure const & base);
		~Cure();

		Cure & operator=(Cure const & base);

		AMateria* clone() const;
		void use(ICharacter& target);
};


#endif
