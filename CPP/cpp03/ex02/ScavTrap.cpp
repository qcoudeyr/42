/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:14:35 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 23:47:21 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name): ClapTrap(Name)
{
	this->_Attack = 20;
	this->_Energy = 50;
	this->_Hit = 100;
	std::cout<< "ScavTrap " + Name + " have been created !"<< std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout<< "ScavTrap " + this->_Name + " have been Destroyed !"<< std::endl;
}

void ScavTrap::attack( std::string const& target )
{
	if ( this->_Energy <= 0 ) {
		std::cout << "ScavTrap " << this->_Name << " is out of energy." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_Name << " attacks " << target << " with a ScavTrap special attack causing " << this->_Attack << " points of damage !" << std::endl;
	this->_Energy -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_Name << " is in Gate keeper mode." << std::endl;
}
