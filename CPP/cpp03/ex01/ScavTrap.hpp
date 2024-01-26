/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:14:34 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 22:17:31 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma one
#include <iostream>
#include <string>

class ScavTrap
{
private:
	std::string _Name;
	unsigned int _Hit;
	unsigned int _Energy;
	unsigned int _Attack;
public:
	ScavTrap(std::string Name);
	~ScavTrap();

	ScavTrap(const ScavTrap &other);
	ScavTrap& operator=(const ScavTrap& other);

	std::string	getName(void) const;
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};
