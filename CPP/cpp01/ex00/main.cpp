/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:04:09 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/23 18:25:06 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	std::string name;

	std::cout << "Creating zombie on the stack. ";
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie stackzombi(name);
	stackzombi.announce();

	std::cout << "Creating zombie on the heap. ";
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie *heapzombi = newZombie(name);
	heapzombi->announce();
	delete heapzombi;

	std::cout << "Creating a Z with randomChump" << std::endl;
	randomChump("randomchump");
	return 0;
}
