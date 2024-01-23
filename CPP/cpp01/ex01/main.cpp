/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:04:09 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/23 18:48:49 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <sstream>

int main( void )
{
	size_t	N;

	std::cout << "Please enter the number of zombie you want to create ! $> N =";
	std::cin>>N;

	Zombie *hordeZombie = zombieHorde(N, "zombie");

	for (size_t i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << i;
		std::string Number = ss.str();
		hordeZombie[i].announce(Number);
	}
	delete [] hordeZombie;
	return 0;
}
