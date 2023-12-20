/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:58:34 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/20 11:26:26 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

void MenuHeader(void)
{
	std::cout<<"#######################"<<std::endl;
	std::cout<<"#       Welcome       #"<<std::endl;
	std::cout<<"#         to          #"<<std::endl;
	std::cout<<"#        your         #"<<std::endl;
	std::cout<<"#      PhoneBook      #"<<std::endl;
	std::cout<<"#######################"<<std::endl;
	std::cout<<"\nWhat do you want to do ?"<<std::endl;
}

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
		MenuHeader();
		std::cout<<"$> ";
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
		else
		{
			std::cout<<"\n Nothing can be done with" + input
		}

	}
	return (0);
}
