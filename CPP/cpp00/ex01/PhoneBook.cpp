/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:58:34 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/20 11:41:30 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

void MenuHeader(std::string str)
{
	std::cout << "\033[2J\033[H";
	std::cout<<"#######################"<<std::endl;
	std::cout<<"#       Welcome       #"<<std::endl;
	std::cout<<"#         to          #"<<std::endl;
	std::cout<<"#        your         #"<<std::endl;
	std::cout<<"#      PhoneBook      #"<<std::endl;
	std::cout<<"#######################"<<std::endl;
	std::cout<<std::endl;
	std::cout<<str<<std::endl;
}

void AddContact(void);
{
	
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

	MenuHeader("What do you want to do ?");

	while (1)
	{
		std::cout<<"$> ";
		std::cin>>input;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			AddContact();
		}
		else if (input == "SEARCH")
		{
			//Do search thing
		}
		else
		{
			MenuHeader("\033[1m\033[31m/!\\ Nothing can be done with '" + input +\
			"'\n\033[0mMay you want to ADD or SEARCH an contact ?");
		}

	}
	return (0);
}
