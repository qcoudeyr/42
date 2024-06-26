/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:20 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/23 12:58:52 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(int argc, char **argv)
{
	(void) argv;
	PhoneBook pb;
	std::string input;

	if (argc > 1)
	{
		std::cout<<"Error ! Usage : $>./PhoneBook"<<std::endl;
		return (0);
	}
	pb.set_NbContact(0);
	while (1)
	{
		pb.MenuHeader("What do you want to do ?");
		std::cout<<"$> ";
		std::cin>>input;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			pb.AddContact();
		else if (input == "SEARCH")
			pb.SearchContact();
		else
		{
			pb.MenuHeader("\033[1m\033[31m/!\\ Nothing can be done with '" + input +\
			"'\n\033[0mMay you want to ADD or SEARCH an contact ?");
		}
	}
	return (0);
}
