/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:41:04 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 22:34:30 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma one
#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string _Name;
	unsigned int _Hit;
	unsigned int _Energy;
	unsigned int _Attack;

	ClapTrap();
public:
	ClapTrap(std::string Name);
	~ClapTrap();

	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap& other);

	std::string	getName(void) const;
	std::string	getAttack(void) const;
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};
