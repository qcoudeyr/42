/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:41:02 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 22:33:58 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap sp1("James"), sp2("Darko");

	sp1.attack(sp2.getName());
	sp2.takeDamage(sp1.);
	sp1.beRepaired(0);
	sp1.attack(cp1.getName());
	sp1.takeDamage(0);
	sp1.beRepaired(0);

	return (0);
}
