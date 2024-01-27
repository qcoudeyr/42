/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:41:02 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 23:21:36 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int main()
{
	FragTrap sp1("James"), sp2("Darko");

	sp1.attack(sp2.getName());
	sp2.takeDamage(sp1.getAttack());
	sp2.beRepaired(5);
	sp1.highFivesGuys();
	sp2.attack(sp1.getName());
	sp1.takeDamage(sp2.getAttack());
	sp1.beRepaired(10);
	sp2.highFivesGuys();

	return (0);
}
