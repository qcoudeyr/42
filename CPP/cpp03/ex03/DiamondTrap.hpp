/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:25:31 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 23:40:44 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

#include <iostream>
#include <string>


class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string _Name;

public:
	DiamondTrap(const std::string& _Name);
	void whoAmI();
	using ScavTrap::attack;
};


#endif
