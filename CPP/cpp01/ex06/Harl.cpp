/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:07 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/24 17:51:03 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout<< "[ DEBUG ]" << std::endl;
	std::cout<< "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void	Harl::info()
{
	std::cout<< "[ INFO ]" << std::endl;
	std::cout<< "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning()
{
	std::cout<< "[ WARNING ]" << std::endl;
	std::cout<< "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error()
{
	std::cout<< "[ ERROR ]" << std::endl;
	std::cout<< "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::complain(std:: string level)
{
	t_level	func[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++ ;
	if (i >= 4)
		std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
	do{
		switch (i) {
			case 0:
				(this->*func[i])();
				break;
			case 1:
				(this->*func[i])();
				break;
			case 2:
				(this->*func[i])();
				break;
			case 3:
				(this->*func[i])();
				break;
		}
	} while (i++ < 4);



}
