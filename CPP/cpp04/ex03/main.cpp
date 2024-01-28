/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:02:29 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:27:30 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "ConcreteMateria.hpp"
#include "Character.hpp"

int main() {
	// Create a character
	Character hero("Hero");

	// Create a materia and clone it
	ConcreteMateria materia;
	AMateria* clonedMateria = materia.clone();

	// Use the cloned materia on the hero
	clonedMateria->use(hero);

	// Clean up
	delete clonedMateria;

	return 0;
}
