/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:42:54 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:42:56 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	public:
		Ice();
		Ice(Ice const & base);
		~Ice();

		Ice & operator=(Ice const & base);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
