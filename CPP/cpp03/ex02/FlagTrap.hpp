/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:12:22 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/26 23:19:04 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap();

public:
	FragTrap(std::string name);
	~FragTrap();

	void highFivesGuys( void );
};

#endif
