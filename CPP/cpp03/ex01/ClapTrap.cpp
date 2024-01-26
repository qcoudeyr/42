/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:41:03 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 22:10:43 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name): _Name(Name), _Hit(10), _Energy(10), _Attack(0)
{
	std::cout<< Name + " have been created !"<< std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout<< this->_Name + " have been Destroyed !"<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
	return;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return *this;
	this->_Attack = other._Attack;
	this->_Energy = other._Energy;
	this->_Hit = other._Hit;
	this->_Name = other._Name;
	return *this;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_Name);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_Energy <= 0)
	{
		std::cout << "ClapTrap " << this->_Name << " is out of energy!" << std::endl;
		return;
	}
	std::cout <<this->_Name + " attacks " + target + ", causing " << this->_Attack << " points of damage !" <<std::endl;
	this->_Energy -= 1;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hit <= amount)
	{
		std::cout << "ClapTrap " <<  this->_Name << " is dead!" << std::endl;
		return;
	}
	std::cout<<this->_Name + " take " << amount << " damage !"<<std::endl;
	this->_Hit -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Energy <= 0)
	{
		std::cout << "ClapTrap " << this->_Name << " is out of energy!" << std::endl;
		return;
	}
	std::cout<<this->_Name + " just repaired " << amount << " health points !"<<std::endl;
	this->_Energy -= 1;
}
