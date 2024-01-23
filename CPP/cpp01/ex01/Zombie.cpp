/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:04:08 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/23 18:47:00 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::set_zombieName(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " + this->_name + " have been destroyed !" << std::endl;
}

void	Zombie::announce(std::string Num)
{
	std::cout << this->_name + " " + Num + " : BraiiiiiiinnnzzzZ..." << std::endl;
}

