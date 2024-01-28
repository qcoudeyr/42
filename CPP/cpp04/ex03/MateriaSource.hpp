/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:47:16 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:49:18 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	protected:
		AMateria *_book[4];
	public:

		MateriaSource();
		MateriaSource(MateriaSource const & base);
		~MateriaSource();

		MateriaSource & operator=(MateriaSource const & base);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & _type);
		AMateria* const & getMateria(int i) const;
};


#endif
