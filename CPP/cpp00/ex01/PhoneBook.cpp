/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:58:34 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/20 11:14:26 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int	main(int argc, char **argv)
{
	(void) argv;
	std::string input;
	if (argc > 1)
	{
		std::cout<<"Error ! Usage : $>./PhoneBook"<<std::endl;
		return (0);
	}
	while (1)
	{
		std::cin>>input;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			//Do Add thing
		}
		else if (input == "SEARCH")
		{
			//Do search thing
		}

	}
	return (0);
}
