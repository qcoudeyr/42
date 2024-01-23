/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:04:07 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/23 18:11:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	~Zombie();
	Zombie* newZombie( std::string name );
	void	announce( void );
	void	randomChump( std::string name );
};

Zombie::Zombie()
{
	std::cout << this->name + " have been created !" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name + " have been destroyed !" << std::endl;
}
