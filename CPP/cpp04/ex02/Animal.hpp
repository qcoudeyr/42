/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:48:34 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 13:59:18 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"


class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(Animal const & base);
		virtual ~Animal();

		Animal& operator=(Animal const & base);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
