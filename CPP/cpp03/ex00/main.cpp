/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:41:02 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 23:47:21 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap cp1("ScavTrap"), cp2("ScavTrap");

	cp1.attack(cp2.getName());
	cp2.takeDamage(0);
	cp2.beRepaired(0);
	cp2.attack(cp1.getName());
	cp1.takeDamage(0);
	cp1.beRepaired(0);

	return (0);
}