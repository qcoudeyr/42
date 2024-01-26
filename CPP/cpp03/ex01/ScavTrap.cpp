/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:14:35 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 22:15:45 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name): _Name(Name), _Hit(10), _Energy(10), _Attack(0)
{
	std::cout<< Name + " have been created !"<< std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout<< this->_Name + " have been Destroyed !"<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
	return;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this == &other)
		return *this;
	this->_Attack = other._Attack;
	this->_Energy = other._Energy;
	this->_Hit = other._Hit;
	this->_Name = other._Name;
	return *this;
}
