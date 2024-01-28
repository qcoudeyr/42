/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:27:46 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 14:30:29 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name) {

}

Character::~Character() {

}

void equip(AMateria* m) {
	// Equip materia (not implemented for simplicity)
}
void Character::unequip(int idx) {
	// Unequip materia (not implemented for simplicity)
}
void Character::use(int idx, ICharacter& target) {
	// Use materia (not implemented for simplicity)
}
std::string Character::getName() const {
	return _name;
}
