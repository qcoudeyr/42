/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:56:04 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/24 16:39:02 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	std::string	input;
	Harl		harl;

	std::cout << "Enter a level: ";
	std::cin >> input;
	harl.complain(input);

	return (0);
}
