/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:12:21 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 23:20:51 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->_Hit = 100;
	this->_Energy = 100;
	this->_Attack = 30;

	std::cout << "FragTrap " + name + " is out of ClapTrap " + name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " + this->_Name + " destructed." << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
	if ( this->_Energy <= 0 )
	{
		std::cout << "FragTrap " + this->_Name + " is out of energy." << std::endl;
		return;
	}
	std::cout << "FragTrap " + this->_Name + " want to give high fives to everyone !" << std::endl;
	this->_Energy -= 1;
}
