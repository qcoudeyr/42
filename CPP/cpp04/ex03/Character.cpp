/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:27:46 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 15:04:44 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {

//	std::cout << "Character default constructor called" << std::endl;
	this->_name = "";
	for (int i = 0; i < 4; i++)
		this->_inv[i] = NULL;
}

Character::Character(std::string name) {

	//	std::cout << "Character string constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inv[i] = NULL;
}

Character::Character(Character const & base) {

	//	std::cout << "Character copy constructor called" << std::endl;
	*this = base;
}

Character::~Character() {

	//	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i])
			delete this->_inv[i];
	}
}


Character & Character::operator=(Character const & base) {
	if (this != &base)
	{
		this->_name = base.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->_inv[i])
				delete this->_inv[i];
			this->_inv[i] = base.getInv(i)->clone();
		}
	}
	return *this;
}


std::string const & Character::getName() const {
	return this->_name;
}

AMateria* const & Character::getInv(int i) const {
	return this->_inv[i];
}

void Character::equip(AMateria* m) {
	int	i;
	for (i = 0; this->_inv[i] && i < 3; i++);
	if (!this->_inv[i])
		this->_inv[i] = m;
	else
		delete m;
}

void Character::unequip(int idx) {
	if (this->_inv[idx])
	{
		delete this->_inv[idx];
		this->_inv[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (this->_inv[idx])
		this->_inv[idx]->use(target);
}
