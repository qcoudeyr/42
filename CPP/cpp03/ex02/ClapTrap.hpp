/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:41:04 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 23:05:08 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

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

	std::string		getName(void) const;
	unsigned int	getAttack(void) const;
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif
