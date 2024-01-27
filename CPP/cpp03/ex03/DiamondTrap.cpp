/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:25:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 23:44:00 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& _Name) : ClapTrap(_Name + "_clap_name"), FragTrap(_Name), ScavTrap(_Name), _Name(_Name)
{
	this->_Hit = FragTrap::_Hit;
	this->_Energy = ScavTrap::_Energy;
	this->_Attack = FragTrap::_Attack;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->_Name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_Name << std::endl;
}
